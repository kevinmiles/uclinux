/* Driver for Lexar "Jumpshot" Compact Flash reader
 *
 * $Id$
 *
 * jumpshot driver v0.1:
 *
 * First release
 *
 * Current development and maintenance by:
 *   (c) 2000 Jimmie Mayfield (mayfield+usb@sackheads.org)
 *
 *   Many thanks to Robert Baruch for the SanDisk SmartMedia reader driver
 *   which I used as a template for this driver.
 *
 *   Some bugfixes and scatter-gather code by Gregory P. Smith 
 *   (greg-usb@electricrain.com)
 *
 *   Fix for media change by Joerg Schneider (js@joergschneider.com)
 *
 * Developed with the assistance of:
 *
 *   (C) 2002 Alan Stern <stern@rowland.org>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
 /*
  * This driver attempts to support the Lexar Jumpshot USB CompactFlash 
  * reader.  Like many other USB CompactFlash readers, the Jumpshot contains
  * a USB-to-ATA chip. 
  *
  * This driver supports reading and writing.  If you're truly paranoid,
  * however, you can force the driver into a write-protected state by setting
  * the WP enable bits in jumpshot_handle_mode_sense.  See the comments
  * in that routine.
  */

#include "transport.h"
#include "protocol.h"
#include "usb.h"
#include "debug.h"
#include "jumpshot.h"

#include <linux/sched.h>
#include <linux/errno.h>
#include <linux/slab.h>

static inline int jumpshot_bulk_read(struct us_data *us,
				     unsigned char *data, 
				     unsigned int len)
{
	if (len == 0)
		return USB_STOR_XFER_GOOD;

	US_DEBUGP("jumpshot_bulk_read:  len = %d\n", len);
	return usb_stor_bulk_transfer_buf(us, us->recv_bulk_pipe,
			data, len, NULL);
}


static inline int jumpshot_bulk_write(struct us_data *us,
				      unsigned char *data, 
				      unsigned int len)
{
	if (len == 0)
		return USB_STOR_XFER_GOOD;

	US_DEBUGP("jumpshot_bulk_write:  len = %d\n", len);
	return usb_stor_bulk_transfer_buf(us, us->send_bulk_pipe,
			data, len, NULL);
}


static int jumpshot_get_status(struct us_data  *us)
{
	int rc;

	if (!us)
		return USB_STOR_TRANSPORT_ERROR;

	// send the setup
	rc = usb_stor_ctrl_transfer(us, us->recv_ctrl_pipe,
				   0, 0xA0, 0, 7, us->iobuf, 1);

	if (rc != USB_STOR_XFER_GOOD)
		return USB_STOR_TRANSPORT_ERROR;

	if (us->iobuf[0] != 0x50) {
		US_DEBUGP("jumpshot_get_status:  0x%2x\n",
			  us->iobuf[0]);
		return USB_STOR_TRANSPORT_ERROR;
	}

	return USB_STOR_TRANSPORT_GOOD;
}

static int jumpshot_read_data(struct us_data *us,
			      struct jumpshot_info *info,
			      u32 sector,
			      u32 sectors)
{
	unsigned char *command = us->iobuf;
	unsigned char *buffer;
	unsigned char  thistime;
	unsigned int totallen, alloclen;
	int len, result;
	unsigned int sg_idx = 0, sg_offset = 0;

	// we're working in LBA mode.  according to the ATA spec, 
	// we can support up to 28-bit addressing.  I don't know if Jumpshot
	// supports beyond 24-bit addressing.  It's kind of hard to test 
	// since it requires > 8GB CF card.

	if (sector > 0x0FFFFFFF)
		return USB_STOR_TRANSPORT_ERROR;

	totallen = sectors * info->ssize;

	// Since we don't read more than 64 KB at a time, we have to create
	// a bounce buffer and move the data a piece at a time between the
	// bounce buffer and the actual transfer buffer.

	alloclen = min(totallen, 65536u);
	buffer = kmalloc(alloclen, GFP_NOIO);
	if (buffer == NULL)
		return USB_STOR_TRANSPORT_ERROR;

	do {
		// loop, never allocate or transfer more than 64k at once
		// (min(128k, 255*info->ssize) is the real limit)
		len = min(totallen, alloclen);
		thistime = (len / info->ssize) & 0xff;

		command[0] = 0;
		command[1] = thistime;
		command[2] = sector & 0xFF;
		command[3] = (sector >>  8) & 0xFF;
		command[4] = (sector >> 16) & 0xFF;

		command[5] = 0xE0 | ((sector >> 24) & 0x0F);
		command[6] = 0x20;

		// send the setup + command
		result = usb_stor_ctrl_transfer(us, us->send_ctrl_pipe,
					       0, 0x20, 0, 1, command, 7);
		if (result != USB_STOR_XFER_GOOD)
			goto leave;

		// read the result
		result = jumpshot_bulk_read(us, buffer, len);
		if (result != USB_STOR_XFER_GOOD)
			goto leave;

		US_DEBUGP("jumpshot_read_data:  %d bytes\n", len);

		// Store the data in the transfer buffer
		usb_stor_access_xfer_buf(buffer, len, us->srb,
				 &sg_idx, &sg_offset, TO_XFER_BUF);

		sector += thistime;
		totallen -= len;
	} while (totallen > 0);

	kfree(buffer);
	return USB_STOR_TRANSPORT_GOOD;

 leave:
	kfree(buffer);
	return USB_STOR_TRANSPORT_ERROR;
}


static int jumpshot_write_data(struct us_data *us,
			       struct jumpshot_info *info,
			       u32 sector,
			       u32 sectors)
{
	unsigned char *command = us->iobuf;
	unsigned char *buffer;
	unsigned char  thistime;
	unsigned int totallen, alloclen;
	int len, result, waitcount;
	unsigned int sg_idx = 0, sg_offset = 0;

	// we're working in LBA mode.  according to the ATA spec, 
	// we can support up to 28-bit addressing.  I don't know if Jumpshot
	// supports beyond 24-bit addressing.  It's kind of hard to test 
	// since it requires > 8GB CF card.
	//
	if (sector > 0x0FFFFFFF)
		return USB_STOR_TRANSPORT_ERROR;

	totallen = sectors * info->ssize;

	// Since we don't write more than 64 KB at a time, we have to create
	// a bounce buffer and move the data a piece at a time between the
	// bounce buffer and the actual transfer buffer.

	alloclen = min(totallen, 65536u);
	buffer = kmalloc(alloclen, GFP_NOIO);
	if (buffer == NULL)
		return USB_STOR_TRANSPORT_ERROR;

	do {
		// loop, never allocate or transfer more than 64k at once
		// (min(128k, 255*info->ssize) is the real limit)

		len = min(totallen, alloclen);
		thistime = (len / info->ssize) & 0xff;

		// Get the data from the transfer buffer
		usb_stor_access_xfer_buf(buffer, len, us->srb,
				&sg_idx, &sg_offset, FROM_XFER_BUF);

		command[0] = 0;
		command[1] = thistime;
		command[2] = sector & 0xFF;
		command[3] = (sector >>  8) & 0xFF;
		command[4] = (sector >> 16) & 0xFF;

		command[5] = 0xE0 | ((sector >> 24) & 0x0F);
		command[6] = 0x30;

		// send the setup + command
		result = usb_stor_ctrl_transfer(us, us->send_ctrl_pipe,
			0, 0x20, 0, 1, command, 7);
		if (result != USB_STOR_XFER_GOOD)
			goto leave;

		// send the data
		result = jumpshot_bulk_write(us, buffer, len);
		if (result != USB_STOR_XFER_GOOD)
			goto leave;

		// read the result.  apparently the bulk write can complete
		// before the jumpshot drive is finished writing.  so we loop
		// here until we get a good return code
		waitcount = 0;
		do {
			result = jumpshot_get_status(us);
			if (result != USB_STOR_TRANSPORT_GOOD) {
				// I have not experimented to find the smallest value.
				//
				msleep(50); 
			}
		} while ((result != USB_STOR_TRANSPORT_GOOD) && (waitcount < 10));

		if (result != USB_STOR_TRANSPORT_GOOD)
			US_DEBUGP("jumpshot_write_data:  Gah!  Waitcount = 10.  Bad write!?\n");

		sector += thistime;
		totallen -= len;
	} while (totallen > 0);

	kfree(buffer);
	return result;

 leave:
	kfree(buffer);
	return USB_STOR_TRANSPORT_ERROR;
}

static int jumpshot_id_device(struct us_data *us,
			      struct jumpshot_info *info)
{
	unsigned char *command = us->iobuf;
	unsigned char *reply;
	int 	 rc;

	if (!us || !info)
		return USB_STOR_TRANSPORT_ERROR;

	command[0] = 0xE0;
	command[1] = 0xEC;
	reply = kmalloc(512, GFP_NOIO);
	if (!reply)
		return USB_STOR_TRANSPORT_ERROR;

	// send the setup
	rc = usb_stor_ctrl_transfer(us, us->send_ctrl_pipe,
				   0, 0x20, 0, 6, command, 2);

	if (rc != USB_STOR_XFER_GOOD) {
		US_DEBUGP("jumpshot_id_device:  Gah! "
			  "send_control for read_capacity failed\n");
		rc = USB_STOR_TRANSPORT_ERROR;
		goto leave;
	}

	// read the reply
	rc = jumpshot_bulk_read(us, reply, 512);
	if (rc != USB_STOR_XFER_GOOD) {
		rc = USB_STOR_TRANSPORT_ERROR;
		goto leave;
	}

	info->sectors = ((u32)(reply[117]) << 24) |
			((u32)(reply[116]) << 16) |
			((u32)(reply[115]) <<  8) |
			((u32)(reply[114])      );

	rc = USB_STOR_TRANSPORT_GOOD;

 leave:
	kfree(reply);
	return rc;
}

static int jumpshot_handle_mode_sense(struct us_data *us,
				      Scsi_Cmnd * srb, 
				      int sense_6)
{
	static unsigned char rw_err_page[12] = {
		0x1, 0xA, 0x21, 1, 0, 0, 0, 0, 1, 0, 0, 0
	};
	static unsigned char cache_page[12] = {
		0x8, 0xA, 0x1, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};
	static unsigned char rbac_page[12] = {
		0x1B, 0xA, 0, 0x81, 0, 0, 0, 0, 0, 0, 0, 0
	};
	static unsigned char timer_page[8] = {
		0x1C, 0x6, 0, 0, 0, 0
	};
	unsigned char pc, page_code;
	unsigned int i = 0;
	struct jumpshot_info *info = (struct jumpshot_info *) (us->extra);
	unsigned char *ptr = us->iobuf;

	pc = srb->cmnd[2] >> 6;
	page_code = srb->cmnd[2] & 0x3F;

	switch (pc) {
	   case 0x0:
		US_DEBUGP("jumpshot_handle_mode_sense:  Current values\n");
		break;
	   case 0x1:
		US_DEBUGP("jumpshot_handle_mode_sense:  Changeable values\n");
		break;
	   case 0x2:
		US_DEBUGP("jumpshot_handle_mode_sense:  Default values\n");
		break;
	   case 0x3:
		US_DEBUGP("jumpshot_handle_mode_sense:  Saves values\n");
		break;
	}

	memset(ptr, 0, 8);
	if (sense_6) {
		ptr[2] = 0x00;		// WP enable: 0x80
		i = 4;
	} else {
		ptr[3] = 0x00;		// WP enable: 0x80
		i = 8;
	}

	switch (page_code) {
	   case 0x0:
		// vendor-specific mode
		info->sense_key = 0x05;
		info->sense_asc = 0x24;
		info->sense_ascq = 0x00;
		return USB_STOR_TRANSPORT_FAILED;

	   case 0x1:
		memcpy(ptr + i, rw_err_page, sizeof(rw_err_page));
		i += sizeof(rw_err_page);
		break;

	   case 0x8:
		memcpy(ptr + i, cache_page, sizeof(cache_page));
		i += sizeof(cache_page);
		break;

	   case 0x1B:
		memcpy(ptr + i, rbac_page, sizeof(rbac_page));
		i += sizeof(rbac_page);
		break;

	   case 0x1C:
		memcpy(ptr + i, timer_page, sizeof(timer_page));
		i += sizeof(timer_page);
		break;

	   case 0x3F:
		memcpy(ptr + i, timer_page, sizeof(timer_page));
		i += sizeof(timer_page);
		memcpy(ptr + i, rbac_page, sizeof(rbac_page));
		i += sizeof(rbac_page);
		memcpy(ptr + i, cache_page, sizeof(cache_page));
		i += sizeof(cache_page);
		memcpy(ptr + i, rw_err_page, sizeof(rw_err_page));
		i += sizeof(rw_err_page);
		break;
	}

	if (sense_6)
		ptr[0] = i - 1;
	else
		((u16 *) ptr)[0] = cpu_to_be16(i - 2);
	usb_stor_set_xfer_buf(ptr, i, srb);

	return USB_STOR_TRANSPORT_GOOD;
}


static void jumpshot_info_destructor(void *extra)
{
	// this routine is a placeholder...
	// currently, we don't allocate any extra blocks so we're okay
}



// Transport for the Lexar 'Jumpshot'
//
int jumpshot_transport(Scsi_Cmnd * srb, struct us_data *us)
{
	struct jumpshot_info *info;
	int rc;
	unsigned long block, blocks;
	unsigned char *ptr = us->iobuf;
	static unsigned char inquiry_response[8] = {
		0x00, 0x80, 0x00, 0x01, 0x1F, 0x00, 0x00, 0x00
	};

	if (!us->extra) {
		us->extra = kmalloc(sizeof(struct jumpshot_info), GFP_NOIO);
		if (!us->extra) {
			US_DEBUGP("jumpshot_transport:  Gah! Can't allocate storage for jumpshot info struct!\n");
			return USB_STOR_TRANSPORT_ERROR;
		}
		memset(us->extra, 0, sizeof(struct jumpshot_info));
		us->extra_destructor = jumpshot_info_destructor;
	}

	info = (struct jumpshot_info *) (us->extra);

	if (srb->cmnd[0] == INQUIRY) {
		US_DEBUGP("jumpshot_transport:  INQUIRY.  Returning bogus response.\n");
		memcpy(ptr, inquiry_response, sizeof(inquiry_response));
		fill_inquiry_response(us, ptr, 36);
		return USB_STOR_TRANSPORT_GOOD;
	}

	if (srb->cmnd[0] == READ_CAPACITY) {
		info->ssize = 0x200;  // hard coded 512 byte sectors as per ATA spec

		rc = jumpshot_get_status(us);
		if (rc != USB_STOR_TRANSPORT_GOOD)
			return rc;

		rc = jumpshot_id_device(us, info);
		if (rc != USB_STOR_TRANSPORT_GOOD)
			return rc;

		US_DEBUGP("jumpshot_transport:  READ_CAPACITY:  %ld sectors, %ld bytes per sector\n",
			  info->sectors, info->ssize);

		// build the reply
		//
		((u32 *) ptr)[0] = cpu_to_be32(info->sectors - 1);
		((u32 *) ptr)[1] = cpu_to_be32(info->ssize);
		usb_stor_set_xfer_buf(ptr, 8, srb);

		return USB_STOR_TRANSPORT_GOOD;
	}

	if (srb->cmnd[0] == MODE_SELECT_10) {
		US_DEBUGP("jumpshot_transport:  Gah! MODE_SELECT_10.\n");
		return USB_STOR_TRANSPORT_ERROR;
	}

	if (srb->cmnd[0] == READ_10) {
		block = ((u32)(srb->cmnd[2]) << 24) | ((u32)(srb->cmnd[3]) << 16) |
			((u32)(srb->cmnd[4]) <<  8) | ((u32)(srb->cmnd[5]));

		blocks = ((u32)(srb->cmnd[7]) << 8) | ((u32)(srb->cmnd[8]));

		US_DEBUGP("jumpshot_transport:  READ_10: read block 0x%04lx  count %ld\n", block, blocks);
		return jumpshot_read_data(us, info, block, blocks);
	}

	if (srb->cmnd[0] == READ_12) {
		// I don't think we'll ever see a READ_12 but support it anyway...
		//
		block = ((u32)(srb->cmnd[2]) << 24) | ((u32)(srb->cmnd[3]) << 16) |
			((u32)(srb->cmnd[4]) <<  8) | ((u32)(srb->cmnd[5]));

		blocks = ((u32)(srb->cmnd[6]) << 24) | ((u32)(srb->cmnd[7]) << 16) |
			 ((u32)(srb->cmnd[8]) <<  8) | ((u32)(srb->cmnd[9]));

		US_DEBUGP("jumpshot_transport:  READ_12: read block 0x%04lx  count %ld\n", block, blocks);
		return jumpshot_read_data(us, info, block, blocks);
	}

	if (srb->cmnd[0] == WRITE_10) {
		block = ((u32)(srb->cmnd[2]) << 24) | ((u32)(srb->cmnd[3]) << 16) |
			((u32)(srb->cmnd[4]) <<  8) | ((u32)(srb->cmnd[5]));

		blocks = ((u32)(srb->cmnd[7]) << 8) | ((u32)(srb->cmnd[8]));

		US_DEBUGP("jumpshot_transport:  WRITE_10: write block 0x%04lx  count %ld\n", block, blocks);
		return jumpshot_write_data(us, info, block, blocks);
	}

	if (srb->cmnd[0] == WRITE_12) {
		// I don't think we'll ever see a WRITE_12 but support it anyway...
		//
		block = ((u32)(srb->cmnd[2]) << 24) | ((u32)(srb->cmnd[3]) << 16) |
			((u32)(srb->cmnd[4]) <<  8) | ((u32)(srb->cmnd[5]));

		blocks = ((u32)(srb->cmnd[6]) << 24) | ((u32)(srb->cmnd[7]) << 16) |
			 ((u32)(srb->cmnd[8]) <<  8) | ((u32)(srb->cmnd[9]));

		US_DEBUGP("jumpshot_transport:  WRITE_12: write block 0x%04lx  count %ld\n", block, blocks);
		return jumpshot_write_data(us, info, block, blocks);
	}


	if (srb->cmnd[0] == TEST_UNIT_READY) {
		US_DEBUGP("jumpshot_transport:  TEST_UNIT_READY.\n");
		return jumpshot_get_status(us);
	}

	if (srb->cmnd[0] == REQUEST_SENSE) {
		US_DEBUGP("jumpshot_transport:  REQUEST_SENSE.\n");

		memset(ptr, 0, 18);
		ptr[0] = 0xF0;
		ptr[2] = info->sense_key;
		ptr[7] = 11;
		ptr[12] = info->sense_asc;
		ptr[13] = info->sense_ascq;
		usb_stor_set_xfer_buf(ptr, 18, srb);

		return USB_STOR_TRANSPORT_GOOD;
	}

	if (srb->cmnd[0] == MODE_SENSE) {
		US_DEBUGP("jumpshot_transport:  MODE_SENSE_6 detected\n");
		return jumpshot_handle_mode_sense(us, srb, TRUE);
	}

	if (srb->cmnd[0] == MODE_SENSE_10) {
		US_DEBUGP("jumpshot_transport:  MODE_SENSE_10 detected\n");
		return jumpshot_handle_mode_sense(us, srb, FALSE);
	}

	if (srb->cmnd[0] == ALLOW_MEDIUM_REMOVAL) {
		// sure.  whatever.  not like we can stop the user from popping
		// the media out of the device (no locking doors, etc)
		//
		return USB_STOR_TRANSPORT_GOOD;
	}

	if (srb->cmnd[0] == START_STOP) {
		/* this is used by sd.c'check_scsidisk_media_change to detect
		   media change */
		US_DEBUGP("jumpshot_transport:  START_STOP.\n");
		/* the first jumpshot_id_device after a media change returns
		   an error (determined experimentally) */
		rc = jumpshot_id_device(us, info);
		if (rc == USB_STOR_TRANSPORT_GOOD) {
			info->sense_key = NO_SENSE;
			srb->result = SUCCESS;
		} else {
			info->sense_key = UNIT_ATTENTION;
			srb->result = SAM_STAT_CHECK_CONDITION;
		}
		return rc;
	}

	US_DEBUGP("jumpshot_transport:  Gah! Unknown command: %d (0x%x)\n",
		  srb->cmnd[0], srb->cmnd[0]);
	info->sense_key = 0x05;
	info->sense_asc = 0x20;
	info->sense_ascq = 0x00;
	return USB_STOR_TRANSPORT_FAILED;
}

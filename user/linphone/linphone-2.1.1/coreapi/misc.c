
/*
linphone
Copyright (C) 2000  Simon MORLAT (simon.morlat@linphone.org)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "private.h"
#include "mediastreamer2/mediastream.h"
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


#ifndef WIN32

static char lock_name[80];
static char lock_set=0;
/* put a lock file in /tmp. this is called when linphone runs as a daemon*/
int set_lock_file()
{
	FILE *lockfile;
	
	snprintf(lock_name,80,"/tmp/linphone.%i",getuid());
	lockfile=fopen(lock_name,"w");
	if (lockfile==NULL)
	{
		printf("Failed to create lock file.\n");
		return(-1);
	}
	fprintf(lockfile,"%i",getpid());
	fclose(lockfile);
	lock_set=1;
	return(0);
}

/* looks if there is a lock file. If presents return its content (the pid of the already running linphone), if not found, returns -1*/
int get_lock_file()
{
	int pid;
	FILE *lockfile;
	
	snprintf(lock_name,80,"/tmp/linphone.%i",getuid());
	lockfile=fopen(lock_name,"r");
	if (lockfile==NULL)
		return(-1);
	if (fscanf(lockfile,"%i",&pid)!=1){
		ms_warning("Could not read pid in lock file.");
		fclose(lockfile);
		return -1;
	}
	fclose(lockfile);
	return pid;
}

/* remove the lock file if it was set*/
int remove_lock_file()
{
	int err=0;
	if (lock_set)
	{
		err=unlink(lock_name);
		lock_set=0;
	}
	return(err);
}

#endif

char *int2str(int number)
{
	char *numstr=ms_malloc(10);
	snprintf(numstr,10,"%i",number);
	return numstr;
}

void check_sound_device(LinphoneCore *lc)
{
	int fd,len;
	int a;
	char *file=NULL;
	char *i810_audio=NULL;
	char *snd_pcm_oss=NULL;
	char *snd_mixer_oss=NULL;
	char *snd_pcm=NULL;
	
	fd=open("/proc/modules",O_RDONLY);
	if (fd>0){
		/* read the entire /proc/modules file and check if sound conf seems correct */
		/*a=fstat(fd,&statbuf);
		if (a<0) ms_warning("Can't stat /proc/modules:%s.",strerror(errno));
		len=statbuf.st_size;
		if (len==0) ms_warning("/proc/modules has zero size!");
		*/
		/***** fstat does not work on /proc/modules for unknown reason *****/
		len=6000;
		file=ms_malloc(len+1);
		a=read(fd,file,len);
		if (a<len) file=ms_realloc(file,a+1);
		file[a]='\0';
		i810_audio=strstr(file,"i810_audio");
		if (i810_audio!=NULL){
			/* I'm sorry i put this warning in comments because
			 * i don't use yet the right driver !! */
/*			lc->vtable.display_warning(lc,_("You are currently using the i810_audio driver.\nThis driver is buggy and so does not work with Linphone.\nWe suggest that you replace it by its equivalent ALSA driver,\neither with packages from your distribution, or by downloading\nALSA drivers at http://www.alsa-project.org."));*/
			goto end;
		}
		snd_pcm=strstr(file,"snd-pcm");
		if (snd_pcm!=NULL){
			snd_pcm_oss=strstr(file,"snd-pcm-oss");
			snd_mixer_oss=strstr(file,"snd-mixer-oss");
			if (snd_pcm_oss==NULL){
				lc->vtable.display_warning(lc,_("Your computer appears to be using ALSA sound drivers.\nThis is the best choice. However the pcm oss emulation module\nis missing and linphone needs it. Please execute\n'modprobe snd-pcm-oss' as root to load it."));
			}
			if (snd_mixer_oss==NULL){
				lc->vtable.display_warning(lc,_("Your computer appears to be using ALSA sound drivers.\nThis is the best choice. However the mixer oss emulation module\nis missing and linphone needs it. Please execute\n 'modprobe snd-mixer-oss' as root to load it."));
			}
		}
	}else {
#ifdef __linux
		ms_warning("Could not open /proc/modules.");
#endif
	}
	/* now check general volume. Some user forget to rise it and then complain that linphone is
	not working */
	/* but some other users complain that linphone should not change levels... 
	if (lc->sound_conf.sndcard!=NULL){
		a=snd_card_get_level(lc->sound_conf.sndcard,SND_CARD_LEVEL_GENERAL);
		if (a<50){
			ms_warning("General level is quite low (%i). Linphone rises it up for you.",a);
			snd_card_set_level(lc->sound_conf.sndcard,SND_CARD_LEVEL_GENERAL,80);
		}
	}
	*/
	end:
	if (file!=NULL) ms_free(file);
	if (fd>0) close(fd);
}

#define UDP_HDR_SZ 8
#define RTP_HDR_SZ 12
#define IP4_HDR_SZ 20   /*20 is the minimum, but there may be some options*/

const char *payload_type_get_description(PayloadType *pt){
	return (const char *)pt->user_data;
}	

void payload_type_set_enable(PayloadType *pt,int value) 
{
	if ((value)!=0) payload_type_set_flag(pt,PAYLOAD_TYPE_ENABLED); \
	else payload_type_unset_flag(pt,PAYLOAD_TYPE_ENABLED); 
}


bool_t payload_type_enabled(PayloadType *pt) {
	return (((pt)->flags & PAYLOAD_TYPE_ENABLED)!=0);
}

int payload_type_get_bitrate(PayloadType *pt)
{
	return pt->normal_bitrate;
}
const char *payload_type_get_mime(PayloadType *pt){
	return pt->mime_type;
}

int payload_type_get_rate(PayloadType *pt){
	return pt->clock_rate;
}

/* return TRUE if codec can be used with bandwidth, FALSE else*/
bool_t linphone_core_check_payload_type_usability(const LinphoneCore *lc, PayloadType *pt)
{
	double codec_band;
	double npacket;
	double packet_size;
	int bitrate;
	int min_audio_bw=get_min_bandwidth(lc->dw_audio_bw,lc->up_audio_bw);
	int min_video_bw=get_min_bandwidth(lc->dw_video_bw,lc->up_video_bw);
	bool_t ret=FALSE;
	
	switch (pt->type){
		case PAYLOAD_AUDIO_CONTINUOUS:
		case PAYLOAD_AUDIO_PACKETIZED:
			if (strcmp(pt->mime_type,"speex")==0 && (pt->clock_rate==8000)){
				/*speex can go down to 8kbit/s */
				bitrate=8000;
			}else bitrate=pt->normal_bitrate;
			/* very approximative estimation... revisit*/
			npacket=50;
			packet_size=(double)(bitrate/(50*8))+UDP_HDR_SZ+RTP_HDR_SZ+IP4_HDR_SZ;
			codec_band=packet_size*8.0*npacket;
			ret=bandwidth_is_greater(min_audio_bw*1000,codec_band);
			//ms_message("Payload %s: %g",pt->mime_type,codec_band);
			break;
		case PAYLOAD_VIDEO:
			if (min_video_bw!=0) {/* infinite (-1) or strictly positive*/
				if (strcmp(pt->mime_type,"H263-1998")==0){
					payload_type_set_recv_fmtp(pt,"CIF=1;QCIF=1");
				}else if (strcmp(pt->mime_type,"H264")==0){
					payload_type_set_recv_fmtp(pt,"packetization-mode=1");
				}
				/*let the video use all the bandwidth minus the maximum bandwidth used by audio */
				if (min_video_bw>0)
					pt->normal_bitrate=min_video_bw*1000;
				else 
					pt->normal_bitrate=512000;
				ret=TRUE;
			}
			else ret=FALSE;
			break;
	}
	/*if (!ret) ms_warning("Payload %s is not usable with your internet connection.",pt->mime_type);*/
	
	return ret;
}

MSList *fix_codec_list(RtpProfile *prof, MSList *conflist)
{
	MSList *elem;
	MSList *newlist=NULL;
	PayloadType *payload,*confpayload;
	
	for (elem=conflist;elem!=NULL;elem=ms_list_next(elem))
	{
		confpayload=(PayloadType*)elem->data;
		payload=rtp_profile_find_payload(prof,confpayload->mime_type,
								confpayload->clock_rate,-1);
		if (payload!=NULL){
			if (ms_filter_codec_supported(confpayload->mime_type)){
				MSFilterDesc *desc=ms_filter_get_encoder(confpayload->mime_type);
				if (payload_type_get_user_data(payload)==NULL){
					payload_type_set_user_data(payload,(void*)desc->text);
					payload_type_set_enable(payload,payload_type_enabled(confpayload));
					newlist=ms_list_append(newlist,payload);
				}/*else this is a duplicate */
			}
		}
		else{
			ms_warning("Cannot support %s/%i: does not exist.",confpayload->mime_type,
								confpayload->clock_rate);
		}
	}
	return newlist;
}


void linphone_core_setup_local_rtp_profile(LinphoneCore *lc)
{
	int i;
	MSList *audiopt,*videopt;
	PayloadType *payload;
	bool_t prepend;
	lc->local_profile=rtp_profile_clone_full(&av_profile);
	
	/* first look at the list given by configuration file to see if 
	it is correct */
	audiopt=fix_codec_list(lc->local_profile,lc->codecs_conf.audio_codecs);
	videopt=fix_codec_list(lc->local_profile,lc->codecs_conf.video_codecs);
	
	/* now find and add payloads that are not listed in the configuration
	codec list */
	for (i=0;i<127;i++)
	{
		payload=rtp_profile_get_payload(lc->local_profile,i);
		if (payload!=NULL){
			if (payload_type_get_user_data(payload)!=NULL) continue;
			/* find a mediastreamer codec for this payload type */
			if (ms_filter_codec_supported(payload->mime_type)){
				MSFilterDesc *desc=ms_filter_get_encoder(payload->mime_type);
				ms_message("Adding new codec %s/%i",payload->mime_type,payload->clock_rate);
				payload_type_set_enable(payload,1);
				payload_type_set_user_data(payload,(void *)desc->text);
				prepend=FALSE;
				/* by default, put speex and theora on top of list*/
				if (strcmp(payload->mime_type,"speex")==0)
					prepend=TRUE;
				if (strcmp(payload->mime_type,"theora")==0)
					prepend=TRUE;
				switch (payload->type){
					case PAYLOAD_AUDIO_CONTINUOUS:
					case PAYLOAD_AUDIO_PACKETIZED:
							if (prepend)
								audiopt=ms_list_prepend(audiopt,(void *)payload);	
							else
								audiopt=ms_list_append(audiopt,(void *)payload);
						break;
					case PAYLOAD_VIDEO:
							if (prepend)
								videopt=ms_list_prepend(videopt,(void *)payload);
							else
								videopt=ms_list_append(videopt,(void *)payload);
						break;
					default:
						ms_error("Unsupported rtp media type.");
				}
			}
		}
	}
	ms_list_for_each(lc->codecs_conf.audio_codecs,(void (*)(void*))payload_type_destroy);
	ms_list_for_each(lc->codecs_conf.video_codecs,(void (*)(void *))payload_type_destroy);
	ms_list_free(lc->codecs_conf.audio_codecs);
	ms_list_free(lc->codecs_conf.video_codecs);
	/* set the fixed lists instead:*/
	lc->codecs_conf.audio_codecs=audiopt;
	lc->codecs_conf.video_codecs=videopt;
}

int from_2char_without_params(osip_from_t *from,char **str)
{
	osip_from_t *tmpfrom=NULL;
	osip_from_clone(from,&tmpfrom);
	if (tmpfrom!=NULL){
		while(!osip_list_eol(&tmpfrom->gen_params,0)){
			osip_generic_param_t *param=(osip_generic_param_t*)osip_list_get(&tmpfrom->gen_params,0);
			osip_generic_param_free(param);
			osip_list_remove(&tmpfrom->gen_params,0);
		}
	}else return -1;
	osip_from_to_str(tmpfrom,str);
	osip_from_free(tmpfrom);
	return 0;
}

bool_t lp_spawn_command_line_sync(const char *command, char **result,int *command_ret){
	FILE *f=popen(command,"r");
	if (f!=NULL){
		int err;
		*result=ms_malloc(4096);
		err=fread(*result,1,4096-1,f);
		if (err<0){
			ms_warning("Error reading command output:%s",strerror(errno));
			ms_free(result);
			return FALSE;
		}
		(*result)[err]=0;
		err=pclose(f);
		if (command_ret!=NULL) *command_ret=err;
		return TRUE;
	}
	return FALSE;
}

#if defined(HAVE_GETIFADDRS) && defined(INET6)
#include <sys/types.h>
#include <sys/socket.h>
#include <ifaddrs.h>
bool_t host_has_ipv6_network()
{
	struct ifaddrs *ifp;
	struct ifaddrs *ifpstart;
	bool_t ipv6_present=FALSE;
	
	if (getifaddrs (&ifpstart) < 0)
	{
		return FALSE;
	}
	
	for (ifp=ifpstart; ifp != NULL; ifp = ifp->ifa_next)
	{
		if (!ifp->ifa_addr)
		  continue;

		switch (ifp->ifa_addr->sa_family) {
		case AF_INET:
		        
			break;
		case AF_INET6:
		    ipv6_present=TRUE;
			break;
		default:
		        continue;
  		}
	}

	freeifaddrs (ifpstart);

	return ipv6_present;
}
#else

bool_t host_has_ipv6_network()
{
	return FALSE;
}


#endif

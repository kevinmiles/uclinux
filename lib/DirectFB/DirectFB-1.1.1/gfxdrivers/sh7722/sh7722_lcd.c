#ifdef SH7722_DEBUG
#define DIRECT_FORCE_DEBUG
#endif


#include <config.h>

#include <asm/types.h>

#include <direct/debug.h>

#include <misc/conf.h>

#include "sh7722.h"


D_DEBUG_DOMAIN( SH7722_LCD, "SH7722/LCD", "Renesas SH7722 LCD" );

/**********************************************************************************************************************/


void
sh7722_lcd_setup( void *drv,
                  int width,
                  int height,
                  ulong phys,
                  int pitch,
                  int bpp )
{
     u32 MLDDFR = 0;
     u32 LDDDSR = 0;

     D_DEBUG_AT( SH7722_LCD, "%s( %dx%d @%lu:%d )\n", __FUNCTION__, width, height, phys, pitch );

     D_ASSERT( width  > 7 );
     D_ASSERT( height > 0 );

     D_ASSERT( (phys & 7) == 0 );

     D_ASSERT( pitch > 0 );
     D_ASSERT( pitch < 0x10000 );
     D_ASSERT( (pitch & 3) == 0 );

     switch (bpp) {
          case 12:
               MLDDFR = 0x8;
               LDDDSR = 0x6;
               break;

          case 16:
               MLDDFR = 0x3;
               LDDDSR = 0x6;
               break;

          case 18:
               MLDDFR = 0x9;
               LDDDSR = 0x4;
               break;

          case 24:
               MLDDFR = 0xb;
               LDDDSR = 0x5;
               break;
     }

     SH7722_SETREG32( drv, LCDC_MLDDCKPAT1R,  0x05555555 );
     SH7722_SETREG32( drv, LCDC_MLDDCKPAT2R,  0x55555555 );
     SH7722_SETREG32( drv, LCDC_LDDCKR,       0x0000003c );
     SH7722_SETREG32( drv, LCDC_MLDMT2R,      0x00000000 );
     SH7722_SETREG32( drv, LCDC_MLDMT3R,      0x00000000 );
     SH7722_SETREG32( drv, LCDC_MLDDFR,       MLDDFR );
     SH7722_SETREG32( drv, LCDC_MLDSM1R,      0x00000000 );
     SH7722_SETREG32( drv, LCDC_MLDSM2R,      0x00000000 );
     SH7722_SETREG32( drv, LCDC_MLDSA1R,	  phys );
     SH7722_SETREG32( drv, LCDC_MLDSA2R,      0x00000000 );
     SH7722_SETREG32( drv, LCDC_MLDMLSR,      pitch );
     SH7722_SETREG32( drv, LCDC_MLDWBCNTR,    0x00000000 );
     SH7722_SETREG32( drv, LCDC_MLDWBAR,      0x00000000 );
#if 0
     SH7722_SETREG32( drv, LCDC_MLDMT1R,      0x18000006 );
     SH7722_SETREG32( drv, LCDC_MLDHCNR,      ((width / 8) << 16) | (1056 / 8) );
     SH7722_SETREG32( drv, LCDC_MLDHSYNR,     ((128 / 8) << 16) | (840 / 8) );
     SH7722_SETREG32( drv, LCDC_MLDVLNR,      (height << 16) | 525 );
     SH7722_SETREG32( drv, LCDC_MLDVSYNR,     (2 << 16) | 490 );
     SH7722_SETREG32( drv, LCDC_MLDPMR,       0xf6000f00 );
#elif 0
     SH7722_SETREG32( drv, LCDC_MLDMT1R,      0x1c00000a );
     SH7722_SETREG32( drv, LCDC_MLDHCNR,      0x00500060);
     SH7722_SETREG32( drv, LCDC_MLDHSYNR,     0x00010052);
     SH7722_SETREG32( drv, LCDC_MLDVLNR,      0x01e00200);
     SH7722_SETREG32( drv, LCDC_MLDVSYNR,     0x000301f0);
     SH7722_SETREG32( drv, LCDC_MLDPMR,       0x00000000 );	//igel
#elif defined(SH7722_ALGO_PANEL)
     SH7722_SETREG32( drv, LCDC_MLDMT1R,      0x1c00000a );
     SH7722_SETREG32( drv, LCDC_MLDHCNR,      0x00500060);
     SH7722_SETREG32( drv, LCDC_MLDHSYNR,     0x00010052);
     SH7722_SETREG32( drv, LCDC_MLDVLNR,      0x01e0020e);
     SH7722_SETREG32( drv, LCDC_MLDVSYNR,     0x000301f0);
     SH7722_SETREG32( drv, LCDC_MLDPMR,       0x00000000 );	//igel
#elif defined(ALGO_AP325)
     SH7722_SETREG32( drv, LCDC_MLDMT1R,      0x1800000a );
     SH7722_SETREG32( drv, LCDC_MLDHCNR,      ((width / 8) << 16) | (1000 / 8) );
     SH7722_SETREG32( drv, LCDC_MLDHSYNR,     ((8 / 8) << 16) | (960 / 8) );
     SH7722_SETREG32( drv, LCDC_MLDVLNR,      (height << 16) | 624 );
     SH7722_SETREG32( drv, LCDC_MLDVSYNR,     (1 << 16) | 560 );
     SH7722_SETREG32( drv, LCDC_MLDPMR,       0xf6000f00 );
#endif
     SH7722_SETREG32( drv, LCDC_LDINTR,       0x00000000 );
     SH7722_SETREG32( drv, LCDC_LDRCNTR,      0x00000000 );
     SH7722_SETREG32( drv, LCDC_LDDDSR,       LDDDSR );
     SH7722_SETREG32( drv, LCDC_LDRCR,        0x00000000 );
     SH7722_SETREG32( drv, LCDC_LDPALCR,      0x00000000 );
     SH7722_SETREG32( drv, LCDC_LDCNT1R,      0x00000001 );
     SH7722_SETREG32( drv, LCDC_LDCNT2R,      0x00000003 );
}


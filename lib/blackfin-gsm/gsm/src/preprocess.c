/*
 * Copyright 1992 by Jutta Degener and Carsten Bormann, Technische
 * Universitaet Berlin.  See the accompanying file "COPYRIGHT" for
 * details.  THERE IS ABSOLUTELY NO WARRANTY FOR THIS SOFTWARE.
 */

#include	<stdio.h>
#include	<assert.h>

#include "private.h"

#include	"gsm.h"
#include 	"proto.h"

/*	4.2.0 .. 4.2.3	PREPROCESSING SECTION
 *  
 *  	After A-law to linear conversion (or directly from the
 *   	Ato D converter) the following scaling is assumed for
 * 	input to the RPE-LTP algorithm:
 *
 *      in:  0.1.....................12
 *	     S.v.v.v.v.v.v.v.v.v.v.v.v.*.*.*
 *
 *	Where S is the sign bit, v a valid bit, and * a "don't care" bit.
 * 	The original signal is called sop[..]
 *
 *      out:   0.1................... 12 
 *	     S.S.v.v.v.v.v.v.v.v.v.v.v.v.0.0
 */


void Gsm_Preprocess P3((S, s, so),
	struct gsm_state * S,
	word		 * s,
	word 		 * so )		/* [0..159] 	IN/OUT	*/
{

	word       z1 = S->z1;
	longword L_z2 = S->L_z2;
	word 	   mp = S->mp;

	word 	   	s1;


	word		SO;

	longword	ltmp;		/* for   ADD */
	ulongword	utmp;		/* for L_ADD */

	int		k;

	for(k=0; k<160; k++) {

	/*  4.2.1   Downscaling of the input signal
	 */
		/* SO = SASR( *s, 3 ) << 2;*/
		SO = SASR( *s, 1 ) & ~3;
		s++;

		assert (SO >= -0x4000);	/* downscaled by     */
		assert (SO <=  0x3FFC);	/* previous routine. */

	/*  4.2.2   Offset compensation
	 * 
	 *  This part implements a high-pass filter and requires extended
	 *  arithmetic precision for the recursive part of this filter.
	 *  The input of this procedure is the array so[0...159] and the
	 *  output the array sof[ 0...159 ].
	 */
		/*   Compute the non-recursive part
		 */

		s1 = SO - z1;			/* s1 = gsm_sub( *so, z1 ); */
		z1 = SO;

		assert(s1 != MIN_WORD);

	/* SJB Remark: float might be faster than the mess that follows */

		/*   Compute the recursive part
		 */

		/*   Execution of a 31 bv 16 bits multiplication
		 */
		{
		word		msp, lsp;
		longword L_s2;
		longword L_temp;
		
		L_s2 = s1;
		L_s2 <<= 15;
#undef __GNUC__ 
#ifndef __GNUC__ 
		msp = SASR( L_z2, 15 );
		lsp = L_z2 & 0x7fff; /* gsm_L_sub(L_z2,(msp<<15)); */

		L_s2  += GSM_MULT_R( lsp, 32735 );
		L_temp = (longword)msp * 32735; /* GSM_L_MULT(msp,32735) >> 1;*/
		L_z2   = GSM_L_ADD( L_temp, L_s2 );
		/* above does L_z2  = L_z2 * 0x7fd5/0x8000 + L_s2 */
#else
		L_z2 = ((long long)L_z2*32735 + 0x4000)>>15;
		
		/* alternate (ansi) version of above line does slightly different rounding:
		 * L_temp = L_z2 >> 9;
		 * L_temp += L_temp >> 5;
		 * L_temp = (++L_temp) >> 1;
		 * L_z2 = L_z2 - L_temp;
		 */
		L_z2 = GSM_L_ADD(L_z2,L_s2);
#endif
		/*    Compute sof[k] with rounding
		 */
		L_temp = GSM_L_ADD( L_z2, 16384 );

	/*   4.2.3  Preemphasis
	 */

		msp   = GSM_MULT_R( mp, -28180 );
		mp    = SASR( L_temp, 15 );
		*so++ = GSM_ADD( mp, msp );
		}
	}

	S->z1   = z1;
	S->L_z2 = L_z2;
	S->mp   = mp;
}

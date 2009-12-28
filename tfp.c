#include <io.h>
#include <stdint.h>
#include "tfp.h"

/* PIC10F pin 1 is ICSPDAT -- msp430 pin 3 */
/* PIC10F pin 3 is ICSPCLK -- msp430 pin 2 */
/* TODO: Not necessarily correct */
#define ICSPDAT (1<<1)
#define ICSPCLK (1<<2)
#define VPP (1<<2)
#define VDD (1<<3)

typedef enum {
	ICSP_INPUTS,
	ICSP_OUTPUTS
} icsp_tris_t;

static inline void icsp_tris( icsp_tris_t v )
{
	const uint8_t mask = ICSPDAT | ICSPCLK;

	if( v == ICSP_INPUTS )
		P1DIR &= ~mask;
	else
		P1DIR |= mask;
}

static inline void icspdat_tris( uint8_t v )
{
	if( v == ICSP_INPUTS )
		P1DIR &= ~ICSPDAT;
	else
		P1DIR |= ICSPDAT;
}

static inline void vpp(uint8_t i)
{
	if(i)
		P1OUT &= ~VPP;
	else
		P1OUT |= VPP;
}

static inline void vdd(uint8_t i)
{
	if(i)
		P1OUT |= VDD;
	else
		P1OUT &= ~VDD;
}

static inline void dat(uint8_t i)
{
	if(i)
		P1OUT |= ICSPDAT;
	else
		P1OUT &= ~ICSPDAT;
}
#define dat_read() (P1IN & ICSPDAT)

#define clk(x) do {			      \
		if(x)			      \
			P1OUT |= ICSPCLK;     \
		else			      \
			P1OUT &= ~ICSPCLK;    \
	} while(0)

static void pause( uint16_t delay )
{
	for(;delay>0;delay--) {
		uint16_t i;
		for(i=0;i<1000;i++);
	}
}

#define PAUSE_INIT 1
/* Pauses defined in the prog spec */
#define PAUSE_PPDP 10
#define PAUSE_HLD0 10
#define PAUSE_TSET1 3
#define PAUSE_THLD1 3
#define PAUSE_TDLY2 3
#define PAUSE_TDLY3 3

void tfp_init( void )
{
	/* Not in programming mode initially */
	icsp_tris( ICSP_INPUTS );

	/* Don't provide VPP */
	vpp(0);
	P1DIR |= VPP;

	/* Do provide VDD */
	vdd(1);
}

void tfp_cmd( uint8_t cmd )
{
	uint8_t i;

	/* TODO: Note similarity between this and tfp_data_write internals */
	for( i=0; i<6; i++ ) {
		clk(1);
		dat( cmd & 1 );
		pause( PAUSE_TSET1 );

		clk(0);
		pause( PAUSE_THLD1 );

		cmd >>= 1;
	}

	pause( PAUSE_TDLY2 );
}

void tfp_data_startstop( void )
{
	clk(1);
	pause( PAUSE_TSET1 );
	clk(0);
	pause( PAUSE_THLD1 );
}

void tfp_data_write( uint16_t data )
{
	uint8_t i;
	icspdat_tris( ICSP_OUTPUTS );

	/* Start (ICSPDAT is don't care) */
	tfp_data_startstop();

	/* 14 clocks */
	for( i=0; i<14; i++ ) {
		clk(1);
		dat( data & 1 );
		pause( PAUSE_TSET1 );

		clk(0);
		pause( PAUSE_THLD1 );
		data >>= 1;
	}

	/* Stop */
	tfp_data_startstop();
}

uint16_t tfp_data_read( void )
{
	uint8_t i;
	uint16_t data = 0;
	icspdat_tris( ICSP_INPUTS );

	/* Start (ICSPDAT is don't care) */
	tfp_data_startstop();

	/* 14 clocks */
	for( i=0; i<14; i++ ) {
		data >>= 1;

		clk(1);
		pause( PAUSE_TDLY3 );
		if( dat_read() )
			data |= 1 << 14;

		clk(0);
		pause( PAUSE_THLD1 );
	}

	/* Stop */
	tfp_data_startstop();

	return data;
}

/* Enter programming mode */
void tfp_enter_prog( void )
{
	vdd(0);
	dat(0);
	clk(0);
	icsp_tris( ICSP_OUTPUTS );
	pause( PAUSE_INIT );

	/* Bring up VDD whilst holding ICSPDAT and ICSPCLK low */
	vdd(1);

	pause( PAUSE_PPDP );
	vpp(1);

	pause( PAUSE_HLD0 );
}

#include "icsp.h"

volatile uint8_t *icsp_OUTP;
volatile uint8_t *icsp_INP;
volatile uint8_t *icsp_DIRP;
uint8_t icsp_CLKB, icsp_DATB;

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

#define DATA_OUT  (*icsp_DIRP |=  _BV(icsp_DATB))
#define DATA_IN   (*icsp_DIRP &= ~_BV(icsp_DATB))

#define CLK_HIGH  (*icsp_OUTP |=  _BV(icsp_CLKB))
#define CLK_LOW   (*icsp_OUTP &= ~_BV(icsp_CLKB))
#define DATA_HIGH (*icsp_OUTP |=  _BV(icsp_DATB))
#define DATA_LOW  (*icsp_OUTP &= ~_BV(icsp_DATB))

#define DATA_VAL  (*icsp_INP & _BV(icsp_DATB))

void icsp_init() {
	/* ICSPCLK to output and ICSPDAT to input */
	*icsp_DIRP |=  _BV(icsp_CLKB);
	*icsp_DIRP &= ~_BV(icsp_DATB);

	/* ICSPCLK low */
	*icsp_OUTP &= ~_BV(icsp_CLKB);
}

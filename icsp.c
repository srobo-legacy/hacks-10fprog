#include "icsp.h"

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

volatile uint8_t *icsp_OUTP;
volatile uint8_t *icsp_INP;
volatile uint8_t *icsp_DIRP;
uint8_t icsp_CLKB, icsp_DATB;

void icsp_init() {
	/* ICSPCLK to output and ICSPDAT to input */
	*icsp_DIRP |=  _BV(icsp_CLKB);
	*icsp_DIRP &= ~_BV(icsp_DATB);

	/* ICSPCLK low */
	*icsp_OUTP &= ~_BV(icsp_CLKB);
}

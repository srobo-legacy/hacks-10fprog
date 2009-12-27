#include "icsp.h"

volatile uint8_t *icsp_OUTP;
volatile uint8_t *icsp_INP;
volatile uint8_t *icsp_DIRP;
uint8_t icsp_CLKB, icsp_DATB, icsp_VPPB;

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

#define DATA_OUT()  (*icsp_DIRP |=  _BV(icsp_DATB))
#define DATA_IN()  (*icsp_DIRP &= ~_BV(icsp_DATB))

#define CLK_HIGH()  (*icsp_OUTP |=  _BV(icsp_CLKB))
#define CLK_LOW()   (*icsp_OUTP &= ~_BV(icsp_CLKB))
#define DATA_HIGH() (*icsp_OUTP |=  _BV(icsp_DATB))
#define DATA_LOW()  (*icsp_OUTP &= ~_BV(icsp_DATB))
#define VPP_HIGH()  (*icsp_OUTP |=  _BV(icsp_VPPB))
#define VPP_LOW()   (*icsp_OUTP &= ~_BV(icsp_VPPB))

#define DATA_VAL()  (*icsp_INP & _BV(icsp_DATB))

void icsp_init() {
	/* ICSP{CLK,DAT} to output */
	*icsp_DIRP |= _BV(icsp_CLKB);
	DATA_OUT();
	/* ICSP{CLK,DAT} low */
	CLK_LOW();
	DATA_LOW();
}

void icsp_vpp_output() {
	*icsp_DIRP |= _BV(icsp_VPPB);
}

void icsp_vpp_set() {
	VPP_LOW();
}

void icsp_vpp_clear() {
	VPP_HIGH();
}

#include "10fprog.h"
#include "icsp.h"

void tenfprog_init(volatile uint8_t *OUTP,
                   volatile uint8_t *INP,
                   volatile uint8_t *DIRP,
                   uint8_t CLKB, uint8_t DATB, uint8_t VPPB) {
	icsp_PORTS[OUT] = OUTP;
	icsp_PORTS[IN]  = INP;
	icsp_PORTS[DIR] = DIRP;
	icsp_PINS[CLK]  = 1 << CLKB;
	icsp_PINS[DATA] = 1 << DATB;
	icsp_PINS[VPP]  = 1 << VPPB;

	/* Ensure the uC doesn't begin in programming mode */
	icsp_vpp_output();
	icsp_vpp_clear();
}

void tenfprog_begin() {
	/* Setup the ICSP interface */
	icsp_init();
	icsp_vpp_set();
}

void tenfprog_end() {
	icsp_vpp_clear();
}

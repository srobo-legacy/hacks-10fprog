#include "10fprog.h"
#include "icsp.h"

void tenfprog_init(volatile uint8_t *OUTP,
                   volatile uint8_t *INP,
                   volatile uint8_t *DIRP,
                   uint8_t CLKB, uint8_t DATB, uint8_t VPPB) {
	icsp_OUTP = OUTP;
	icsp_INP  = INP;
	icsp_DIRP = DIRP;
	icsp_CLKB = CLKB;
	icsp_DATB = DATB;
	icsp_VPPB = VPPB;

	icsp_init();
}

#include "icsp.h"

volatile uint8_t *icsp_PORTS[3];
uint8_t icsp_PINS[3];

#define SET_BIT(p, b) ((p) |= b)
#define CLEAR_BIT(p, b) ((p) &= b)

#define PIN_OUT(p)  SET_BIT(*icsp_PORTS[DIR], icsp_PINS[p])
#define PIN_IN(p)   CLEAR_BIT(*icsp_PORTS[DIR], icsp_PINS[p])

#define PIN_HIGH(p) SET_BIT(*icsp_PORTS[OUT], icsp_PINS[p])
#define PIN_LOW(p)  CLEAR_BIT(*icsp_PORTS[OUT], icsp_PINS[p])

#define PIN_VAL(p)  (*icsp_PORTS[IN] & _BV(icsp_PINS[p]))

void icsp_init() {
	/* ICSP{CLK,DAT} to output */
	PIN_OUT(CLK);
	PIN_OUT(DATA);
	/* ICSP{CLK,DAT} low */
	PIN_LOW(CLK);
	PIN_LOW(DATA);
}

void icsp_vpp_output() {
	PIN_OUT(VPP);
}

void icsp_vpp_set() {
	PIN_LOW(VPP);
}

void icsp_vpp_clear() {
	PIN_HIGH(VPP);
}

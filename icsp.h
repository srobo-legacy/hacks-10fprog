#ifndef __ICSP_H
#define __ICSP_H
#include <stdint.h>

enum PORTS {
	OUT, IN, DIR
};
enum PINS {
	CLK, DATA, VPP
};

extern volatile uint8_t *icsp_PORTS[3];
extern uint8_t icsp_PINS[3];

void icsp_init(void);

/* Control VPP pin to enter/leave programming mode */
void icsp_vpp_output(void);
void icsp_vpp_set(void);
void icsp_vpp_clear(void);

#endif /* __ICSP_H */

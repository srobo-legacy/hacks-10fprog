#ifndef __ICSP_H
#define __ICSP_H
#include <stdint.h>

extern volatile uint8_t *icsp_OUTP;
extern volatile uint8_t *icsp_INP;
extern volatile uint8_t *icsp_DIRP;
extern uint8_t icsp_CLKB, icsp_DATB, icsp_VPPB;

void icsp_init(void);

/* Control VPP pin to enter/leave programming mode */
void icsp_set_vpp(void);
void icsp_clear_vpp(void);

#endif /* __ICSP_H */

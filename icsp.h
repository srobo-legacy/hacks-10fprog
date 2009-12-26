#ifndef __ICSP_H
#define __ICSP_H
#include <stdint.h>

extern volatile uint8_t *icsp_OUTP;
extern volatile uint8_t *icsp_INP;
extern volatile uint8_t *icsp_DIRP;
extern uint8_t icsp_CLKB, icsp_DATB;

void icsp_init(void);

#endif /* __ICSP_H */

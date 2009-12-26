/* Library for progamming a PIC10Fxxx device from another microcontroller */
#ifndef __10fprog_H
#define __10fprog_H
#include <stdint.h>

/* Initialize 10fprog, must be run before any other functions in this lib.
 *
 * OUTP, INP, DIRP: Pointers to the output, input and direction registers of the
 *                  port used for the ICSPCLK and ICSPDAT lines.
 * CLKB, DATB:      Bit positions for the ICSP pins on the port.
 */
void tenfprog_init(volatile uint8_t *OUTP, volatile uint8_t *INP,
                   volatile uint8_t *DIRP, uint8_t CLKB, uint8_t DATB);

#endif /* __10fprog_H */

MSP_CC = msp430-gcc
MSP_AR = msp430-ar
MSP_ARCH = msp430x2002

AVR_CC = avr-gcc
AVR_AR = avr-ar
AVR_OBJCOPY = avr-objcopy
AVR_ARCH = atmega88

CFLAGS = -g -Wall -O2
LDFLAGS = -L .. -l10fprog

test-msp430: test-msp430.c lib10fprog.msp.a
	${MSP_CC} -o $@ $< ${CFLAGS} -mmcu=${MSP_ARCH} ${LDFLAGS}

test-avr: test-avr.hex
	

test-avr.hex: test-avr.out
	${AVR_OBJCOPY} -j .text -j .data -O ihex $< $@
	
test-avr.out: test-avr.c lib10fprog.avr.a
	${AVR_CC} -o $@ $< ${CFLAGS} -mmcu=${AVR_ARCH} ${LDFLAGS}

lib10fprog.avr.a:
	${MAKE} -C .. CC="${AVR_CC}" AR="${AVR_AR}" ARCH="${AVR_ARCH}" CFLAGS="${CFLAGS}"

lib10fprog.msp.a:
	${MAKE} -C .. CC="${MSP_CC}" AR="${MSP_AR}" ARCH="${MSP_ARCH}" CFLAGS="${CFLAGS}"

.PHONY: clean

clean:
	-rm -f test-avr.out test-avr.hex test-msp430
	${MAKE} -C .. clean

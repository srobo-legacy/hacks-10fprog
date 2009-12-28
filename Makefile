ARCH=msp430x2002
CC := msp430-gcc
CFLAGS := -g -mmcu=${ARCH} -Wall -Os

main: main.c tfp.c

.PHONY: clean

clean:
	-rm -f main

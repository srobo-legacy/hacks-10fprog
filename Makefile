ifeq ($(origin CC), default)
$(info No CC specified on the command line, defaulting to msp430-gcc)
CC = msp430-gcc
endif

ifeq ($(origin AR), default)
$(warning No AR specified on the command line, defaulting to msp430-ar, this must match the comiler from CC)
AR = msp430-ar
endif

ifndef ARCH
$(warning No uC ARCH set. Set on the command line: make ARCH="msp430x2234. Defaulting to msp430x2234")
ARCH = msp430x2234
endif

CFLAGS ?= -g -mmcu=${ARCH} -Wall

C_FILES = 10fprog.c icsp.c
H_FILES = 10fprog.h icsp.h

lib10fprog.a: 10fprog.o icsp.o
	${AR} r $@ 10fprog.o icsp.o

%.o: %.c %.h
	${CC} -c -o $@ ${CFLAGS} $<

.PHONY: clean

clean:
	-rm -f *.o lib10fprog.a


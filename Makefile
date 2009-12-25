ifeq ($(origin CC), default)
$(info No CC specified on the command line, defaulting to msp430-gcc)
CC = msp430-gcc
endif

ifndef ARCH
$(error No uC ARCH set. Set on the command line: make ARCH="msp430x2234")
endif

CFLAGS ?= -g -mmcu=${ARCH} -Wall

main: main.c


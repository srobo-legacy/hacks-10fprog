ARCH=msp430x2001
CC := msp430-gcc
CFLAGS := -g -mmcu=${ARCH} -Wall

main: main.c

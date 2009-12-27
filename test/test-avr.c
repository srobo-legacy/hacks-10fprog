#include <avr/io.h>
#include "10fprog.h"

void init();

int main() {
	init();
	
	while(1);
	return 0;
}

void init() {
	tenfprog_init(&PORTB, &PINB, &DDRB, 0, 1, 2);
}

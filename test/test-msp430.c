#include <io.h>
#include "10fprog.h"

void init( void );

int main( void )
{
	/* Disable the watchdog timer */
	WDTCTL = WDTHOLD | WDTPW;

	init();

	while(1);
	return 0;
}

void init( void )
{
	/* Inputs */
	P1DIR = P2DIR = 0;
	
	/* Need chaning to correct values */
	tenfprog_init(&P1OUT, &P1IN, &P1DIR, 0, 1);

}

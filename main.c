#include <io.h>
#include "tfp.h"

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
	
	tfp_init();
}

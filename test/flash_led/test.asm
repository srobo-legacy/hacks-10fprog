PROCESSOR 10F200
#include "p10f200.inc"

	__CONFIG _MCLRE_OFF & _CP_OFF & _WDT_OFF

	org	0x00
Loop:	goto Loop

	end

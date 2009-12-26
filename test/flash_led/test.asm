PROCESSOR 10F200
#include "p10f200.inc"

	; Disable reset pin, code protection and watchdog timer
	__CONFIG _MCLRE_OFF & _CP_OFF & _WDT_OFF

	cblock	0x10		; Start of GP registers
		count1		; Variables used for Delay routine
		counta
		countb
	endc

	org	0x00
	
	movlw	b'11011111'	; Disable Timer input on GP2 pin
	option
	
	movlw	b'00001011'	; Set GP2 to output
	tris	GPIO

Loop:	bsf	GPIO, GP2
	call	Delay
	bcf	GPIO, GP2
	call	Delay
	goto Loop



Delay:	movlw	d'250'		; 250mS overall delay
	movwf	count1

d1:	movlw	0xC7		; 1mS delay with 4MHz clock
	movwf	counta
	movlw	0x01
	movwf	countb

d2:	decfsz	counta, f
	goto	$+2
	decfsz	countb, f
	goto	d2

	decfsz	count1,	f
	goto	d1

	retlw	0x00



	end

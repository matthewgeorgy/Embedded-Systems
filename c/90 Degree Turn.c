/*  author: haHAA
	last update: 
	Description: 
	Hardware setup:


*/
#include <pic.h>	// include a library of procedure specific to the PIC family of microcontrollers
#include <htc.h>
__CONFIG( FOSC_INTRCIO & WDTE_OFF & PWRTE_OFF & MCLRE_OFF & CP_OFF & CPD_OFF & BOREN_OFF & 
IESO_OFF & FCMEN_OFF );

//defined constants- the compiler does a substitution 


//Global Variables 
int done=0;
// PREDEFINE PROCEDURES: procedure must be defined before you can use them

void init_hardware(void);

void main(void)
{
			init_hardware();
			PORTC=0b00000000;
			while(1)
			{
			RC0=1,RC1=0,RC3=0,RC4=1;
			_delay(1200000); 
			RC0=1,RC1=0,RC3=1,RC4=0;
			_delay(1000000);
			}
			
}//end of main()
void init_hardware(void)   //set it and forget it
{
	// set analogue pins as analogue(1) or digital(0) 
	ANSEL  = 0b00000000;           // AN7 to AN0
	ANSELH = 0b00000000;	       //  n/c , n/c, n/c, n/c, AN11, AN10,AN9, AN8
	
       // set pins as Input(1) or Output(0)
	TRISA = 0b00110000;	
	TRISB = 0b00000000;
	TRISC = 0b00000000;
	
       //initalize the ports 
	PORTA = 0b00000000;
	PORTB = 0b00000000;
	PORTC = 0b00000000;	
}

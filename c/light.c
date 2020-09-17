/*  author: haHAA
	last update: 
	Description: 
	Hardware setup:


*/
#include <pic.h>	// include a library of procedure specific to the PIC family of microcontrollers
#include <htc.h>
#include <stdio.h>
__CONFIG( FOSC_INTRCIO & WDTE_OFF & PWRTE_OFF & MCLRE_OFF & CP_OFF & CPD_OFF & BOREN_OFF & 
IESO_OFF & FCMEN_OFF );

//defined constants- the compiler does a substitution 


//Global Variables
unsigned char sens;
// PREDEFINE PROCEDURES: procedure must be defined before you can use them

void init_hardware(void);

void main(void)
{
	PORTC=0b00000000;
	init_hardware();
	while(1)
	{
		GO_DONE = 1;
		while(GO_DONE == 1)
		{
				//wait for the ADC to be done
		}
		PORTC=ADRESH;
		_delay(1000000);
		/*if(sens<145){
		RC0=1, RC1=0, RC3=0, RC4=0;
		_delay(100);
		}//black
		else if(sens>145){//black
		RC0=0, RC1=0, RC3=1, RC4=0;
		_delay(100);
		}
	*/
	}			//end of while			
}//end of main()
void init_hardware(void)   //set it and forget it
{
	// set analogue pins as analogue(1) or digital(0) 
	ANSEL  = 0b00000000;           // AN7 to AN0
	ANSELH = 0b00001000;	       //  n/c , n/c, n/c, n/c, AN11, AN10,AN9, AN8
	
       // set pins as Input(1) or Output(0)
	TRISA = 0b00110000;	
	TRISB = 0b00100000;
	TRISC = 0b00000000;
	
       //initalize the ports 
	PORTA = 0b00000000;
	PORTB = 0b00000000;
	PORTC = 0b00000000;	
	
	//initialize the sensors
	ADCON0=0b00101101;
}

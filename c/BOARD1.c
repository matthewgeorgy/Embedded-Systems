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
int endCounter = 0;

// PREDEFINE PROCEDURES: procedure must be defined before you can use them

void init_hardware(void);

void main(void)
{
PORTC=0b00000000;
unsigned char rightSensor;
unsigned char leftSensor;
	init_hardware();
	while(1){
		//right sensor
		GO_DONE=1;
		while(GO_DONE==1){}
		rightSensor=ADRESH;
		_delay(10000);
		
		//left sensor	
		ADCON0bits.CHS=0B1010;
		_delay(10);
		GO_DONE=1;
		while(GO_DONE==1){}
		leftSensor=ADRESH;
		_delay(10000);	
		//execution	
		if (rightSensor<12&&leftSensor>12)//right side on black ONLY
				{
					RC3=1;
					_delay(100);
				}//end of if-RIGHT BLACK
		else if (leftSensor<12&&rightSensor>12)//left side on black 
				{
					RC1=1;
					_delay(100);
				}//end of if-LEFT BLACK
		else if (leftSensor<12&&rightSensor<12)//both sides on black
				{
					if (endCounter%2==0)
					{
						int lightFlash=0;
						while(lightFlash<endCounter)
							{
							RC7=1;
							_delay(100);
							RC7=0;
							_delay(100);
							lightFlash++;
							}//end of while	
					}//end of if
				
					_delay(100);
					endCounter++;
				}//end of if-- BOTH BLACK
		else //on white
				{
					RC1,RC3=1;
					_delay(100);		
				}//end of else-- BOTH WHITE
	
	}//end of while			
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
	ADCON0=0B10101101;
}

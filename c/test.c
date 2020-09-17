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
	unsigned char rightSensor;
	unsigned char leftSensor;
	int onBlack=1;
// PREDEFINE PROCEDURES: procedure must be defined before you can use them

void init_hardware(void);

void main(void)
{
PORTC=0b00000000;
	init_hardware();
	while(1){
		RC5=1;
		_delay(500000);
		RC5=0;
		_delay(500000);	
	}	//end of while			
}		//end of main()
			
		
void init_hardware(void)   //set it and forget it
{
	// set analogue pins as analogue(1) or digital(0) 
	ANSEL  = 0b00000000;           // AN7 to AN0
	ANSELH = 0b00001100;	       //  n/c , n/c, n/c, n/c, AN11, AN10,AN9, AN8
	//initialize the sensors
	ADCON0=0B00101101;	
	
	
       // set pins as Input(1) or Output(0)
	TRISA = 0b00100000;	
	TRISB = 0b00110000;
	TRISC = 0b00000000;
	
       //initalize the ports 
	PORTA = 0b00000000;
	PORTB = 0b00000000;
	PORTC = 0b00000000;	
	

}




else if(onBlack==6){
			onBlack=7;
			//forward
			RC0=1, RC1=0, RC3=1, RC4=0;
			_delay(300000);
				while(timer<60)
				{
					//right sensor
					ADCON0bits. CHS=0B1011;
					GO_DONE=1;
					while(GO_DONE==1){}
					rightSensor=ADRESH;
					_delay(10);
					
					//left sensor	
					ADCON0bits.CHS=0B1010;
					GO_DONE=1;
					while(GO_DONE==1){}
					leftSensor=ADRESH;
					_delay(10);
					timer++;
		
				/*if (lines==1){
						PORTC=0b00000000;
						_delay(50000);
						unsigned char index=0;
						while (index<(timer))
						{
							PORTC=0b00000000;
							_delay(500000);
							RC5=1;
							_delay(50000);
							index=index+2;
						}	
						break;
					}			
		*/
			//slow forward

			RC0=1, RC1=0, RC3=1, RC4=0;
			_delay(10000);	
			PORTC=0b00000000;
			_delay(1000);	
	
			if ((rightSensor>145)&&(leftSensor>145))// both black
			{
					lines++;
					RC7=1;
					_delay(1000);
			}	
			}//end of while
			PORTC=0b00000000;
			_delay(5000);
		
				unsigned char index=1;
				while (index<=lines)
						{
							PORTC=0b00000000;
							_delay(500000);
							RC5=1;
							_delay(500000);
							index++;
						}	
			}//end of else if
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
	int lines=0;
	unsigned char timer=0;
 	unsigned char duration=0;
// PREDEFINE PROCEDURES: procedure must be defined before you can use them

void init_hardware(void);

void main(void)
{
	init_hardware();
	while(1){
		//forward
			RC0=1, RC1=0, RC3=1, RC4=0, RC6=1;
			_delay(300000);
			PORTC=0b00000000;
				while(1)
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
					if ((timer%30==0))
					{
						//right
					RC0=0, RC1=1, RC3=1, RC4=0;
					_delay(33000);
					}
					else
					{
					//slow forward
					RC0=1, RC1=0, RC3=1, RC4=0;
					_delay(6000);	
					PORTC=0b00000000;
					_delay(40000);	
					}
				
					if ((rightSensor>145)||(leftSensor>145))// either black
					{ 	
						RC0=1, RC1=0, RC3=1, RC4=0, RC6=1;
						_delay(135000);
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
						if ((rightSensor>145)||(leftSensor>145))// either black
						{
							//right
							RC0=0, RC1=1, RC3=1, RC4=0;
							_delay(900000);
							onBlack=7;
							break;
						}
						else
						{
						lines++;
						RC5=1;
						_delay(1000);
						}

				}//end of while				

			PORTC=0b00000000;
			_delay(500);
			unsigned char index=1;
				while (index<=lines)
						{
							PORTC=0b00000000;
							_delay(500000);
							RC5=1;
							_delay(500000);
							index++;
						}}
	}					
}//end of main()

		
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

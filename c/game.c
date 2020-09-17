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
// PREDEFINE PROCEDURES: procedure must be defined before you can use them

void init_hardware(void);

void main(void)
{
PORTC=0b00000000;
	init_hardware();
	while(1){
		PORTC=0b00000000;
	//right sensor
		ADCON0bits. CHS=0B1011;
		GO_DONE=1;
		while(GO_DONE==1){}
		rightSensor=ADRESH;
		_delay(100);
	//left sensor	
		ADCON0bits.CHS=0B1010;
		GO_DONE=1;
		while(GO_DONE==1){}
		leftSensor=ADRESH;
		_delay(100);
		
	//execution	
		if ((rightSensor<=145)&& (leftSensor<145))// both on white
		{
			//forward
		RC0=1, RC1=0, RC3=1, RC4=0; 
			//backward
		//RC0=0, RC1=1, RC3=0, RC4=1;
			//left
		//RC0=1, RC1=0, RC3=0, RC4=1;
			//right
		//RC0=0, RC1=1, RC3=1, RC4=0;
			
			_delay(1000);
			
		}
		else if ((rightSensor<145)&& (leftSensor>=145))// right black left white
		{
			RC0=1, RC1=0, RC3=0, RC4=1;
			_delay(1000);
		}
	    
	    else if ((rightSensor>=145)&& (leftSensor<=145))// left black right white
		{
			RC0=0, RC1=1, RC3=1, RC4=0;
			_delay(1000);
		}
		
		else if ((rightSensor>145)&&(leftSensor>145))// both black
		{	
			PORTC=0b00000000;
			if (onBlack==1){
				//forward
			RC0=1, RC1=0, RC3=1, RC4=0; 
			RC7=1;
			_delay(550000);
			onBlack=2;
			}
			else if(onBlack==2){
				//right
			RC0=0, RC1=1, RC3=1, RC4=0;
			RC6=1;
			_delay(400000);
			onBlack=3;
			}
			else if(onBlack==3){
				//right
			RC0=0, RC1=1, RC3=1, RC4=0;
			RC6=1;
			_delay(200000);
			onBlack=4;
			}	
			else if(onBlack==4){
				//right
			RC0=0, RC1=1, RC3=1, RC4=0;
			RC6=1;
			_delay(170000);
			onBlack=5;
			}
			else if(onBlack==5){
				//forward
			RC0=1, RC1=0, RC3=1, RC4=0; 
			RC7=1;
			_delay(450000);
				//right
			RC0=0, RC1=1, RC3=1, RC4=0;
			RC6=1;
			_delay(450000);
			onBlack=6;
			}
			else if(onBlack==6){
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
			if ((timer==30))
			{
				//right
			RC0=0, RC1=1, RC3=1, RC4=0;
			_delay(90000);
			}
		/*	if (timer==75)
			{
				//right
			RC0=0, RC1=1, RC3=1, RC4=0;
			_delay(15000);
			}*/
			else
			{
			//slow forward
			RC0=1, RC1=0, RC3=1, RC4=0;
			_delay(9000);	
			PORTC=0b00000000;
			_delay(20000);	
			}
			
			if ((rightSensor>145)||(leftSensor>145))// either black
			{ 	
				RC0=1, RC1=0, RC3=1, RC4=0, RC6=1;
				_delay(110000);
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
					_delay(1000000);
					break;
				}
				else
				{
				lines++;
				RC5=1;
				_delay(1000);
				}
			}				
		}//end of else if
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
						}
						
			}	
			
	
		}//end of else
	}//end of while			
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

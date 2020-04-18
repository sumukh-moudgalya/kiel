//Header file for using microcontroller 
#include <reg52.h>

//Delay function prototype
void delay();

//Beginning of the program

void main(){
	TMOD=0x01;//Selecting timer 0 and mode 1
	//Running the loop continuosly
	while(1){
		//Logic high at port 1 for square wave
		P1=0XFF;
		//providing a delay of 5ms
		delay();
		//Logic low at port 1 for square wave
		P1=0X0;
		//Providing a delay of 5ms
		delay();
	}
}


//Defigning the function delay

void delay(){
	//Choosing the timer 0
	TR0=1;
	//setting the timer TL of timer 0 to 0
	TL0=0X0;
	//setting the timer TH of timer 0 to EE for 5 ms delay
	TH0=0XEE;

	while(!TF0);//or while(TF==0)

	//deselecting the timer to end the delay
	TR0=0;

	//Setting the overflow flag of timer to 0 for using it again
	TF0=0;


}



/*
===================================================================================================================================================
																Calculation
																
																1 count=1.085us
																x count=5ms
																==> x=4608
																since it is a up counter.
																x=65536-4608=60928
																x=60928=EE00(in hex)
																==> TH0=EE , TL0=00

====================================================================================================================================================
*/

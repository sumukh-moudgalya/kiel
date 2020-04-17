#include<reg52.h>
// SETTING RS,RW,ENABLE PIN TO RESPECTIVE PINS OF PORT 2
sbit RS=P2^0;
sbit RW=P2^1;
sbit E=P2^2;

void send_command(unsigned int com);
void send_data(unsigned int ata);
void delay_ms(unsigned int time);


void main(){
		//SETTING UP LCD DISPLAY 2*16(5*7 MATRIX)
		send_command(0x38);

		//DISPLAY ON CURSOR BLINK
		send_command(0x0E);

		//CLEAR DISPLAY SCREEN COMMAND
		send_command(0x01);
		//SENDING THE CHARACTER FOR DISPLAY
		while(1){
			//FORCING CURSOR TO DISPLAY ON FIRST LINE
			send_command(0x80);
			//PRINTING CHARACTER ON FIRST LINE OF LCD 
			send_data('F');
			send_data('U');
			send_data('C');
			send_data('K');

			//FORCING CURSOR TO DISPLAY ON SECOND LINE
			send_command(0xC0);
			//DISPLAYING CHARACTERS ON SECOND LINE
			send_data('Y');
			send_data('O');
			send_data('U');
		}


}
//DEFINING THE FUNCTION FOR SENDING  COMMAND
void send_command(unsigned int com){
	P1=com;//SENDING THE COMMAND TO THE PORT
	RW=0;//ENABLING THE WRITE MODE
	RS=0;//SELECTING COMMAND REGISTER FOR DATA TRANSFER
	E=1;//ENABLING THE PIN TO LOAD THE DATA TO THE REGISTER
	delay_ms(10);
	E=0;

}

//DEFINING THE FUNCTION FOR SENDING DATA
void send_data(unsigned int ata){
	P1=ata;//SENDING THE COMMAND TO THE PORT
	RW=0;//ENABLING THE WRITE MODE
	RS=1;//SELECTING DATAREGISTER FOR DATA TRANSFER
	E=1;//ENABLING THE PIN TO LOAD THE DATA TO THE REGISTER
	delay_ms(10);
	E=0;

}

void delay_ms(unsigned int time){
	//DELAY IN ms
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<time;j++);
	}
}



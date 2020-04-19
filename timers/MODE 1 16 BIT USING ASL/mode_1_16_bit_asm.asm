//setting the origin
ORG 0000H;

 
MOV TMOD,#01H									;selecting 16-bit timer i.e, mode 1 

LOOP1:														;running the program continously 

MOV P1,#0FFH												;logic high at port 1 for square wave

ACALL DELAY													;providing a delay of 5ms

MOV P1,#0H													;logic low at port 1 for square wave

ACALL DELAY													;providing a delay of 5ms

SJMP LOOP1													;calling the loop again

DELAY:														;defining the subroutine delay

SETB TR0													;selecting timer 0

MOV TL0,#0H													;setting the data of TL0 to 0

MOV TH0,#0EEH												;setting the data of TH0 to EE

LOOP2:

JNB TF0,LOOP2												;jump if TF0 bit is not set to LOOP2

CLR TR0														;deselect the timer 0

CLR TF0														;setting the overflow flag of timer to 0 for using it again

RET															;return

END;




















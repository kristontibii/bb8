#include "Pin_Config.h"
#include "Read_joystick.h"



void Read_joystick_1(){

  JOYSTICK1 joy1;


  
  joy1.x_value = analogRead(joystick2_X)/4;
  joy1.y_value = analogRead(joystick2_X)/4;

  
}

void Read_joystick_2(){

	JOYSTICK1 joy2;

	  joy2.x_value = analogRead(joystick2_X)/4;
	  joy2.y_value = analogRead(joystick2_X)/4;
}

void Read_joystick_3(){

	JOYSTICK1 joy3;

	  joy3.x_value = analogRead(joystick2_X)/4;
	  joy3.y_value = analogRead(joystick2_X)/4;
}



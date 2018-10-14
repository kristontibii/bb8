#include <Arduino.h>
#include "Init.h"
#include "Pin_Config.h"
#include "Applications/Display/oled.h"
#include "Read_digital_pins.h"
#include "Read_joystick.h"


#define DEBUG

void setup() {

#ifndef DEBUG
	Serial.begin(9600);
	Serial.println("Debug mode is active");
#endif



	if(InitStatus != 0)
		{
		Init_Pins();
		}
	else
		{
		//Do Nothing
		}


}

void loop() {

#ifndef DEBUG
	Serial.println("Debug mode is active");
#endif
}

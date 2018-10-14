/* init functions have to be defined here */
#include "Init.h"
#include "Arduino.h"
#include "Pin_Config.h"


void Init_Pins()
{
	pinMode(joystick1_X, INPUT);
	pinMode(joystick1_Y, INPUT);

	pinMode(joystick2_X, INPUT);
	pinMode(joystick2_Y, INPUT);

	pinMode(joystick3_X, INPUT);
	pinMode(joystick3_Y, INPUT);

	pinMode(Button_Pin_1, INPUT);
	pinMode(Button_Pin_2, INPUT);
	pinMode(Button_Pin_3, INPUT);
	pinMode(Button_Pin_4, INPUT);

	pinMode(Button_Pin_Scroll_Left, INPUT);
	pinMode(Button_Pin_Scroll_Right, INPUT);

	pinMode(LED_DISPLAY_SCL, INPUT);
	pinMode(LED_DISPLAY_SDA, INPUT);

	InitStatus = 1;
}

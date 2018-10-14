/*
 * BB8_MainDrive_Atmel.cc
 *
 *  Created on: 2018. okt. 5.
 *      Author: Kriston Tibor
 */


#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <Wire.h>
#include <AccelStepper.h>
#include <AFMotor.h>
#include <Servo.h>

#define DEBUG
	int i;
	int j;
// DC motor on M2


Servo servo1;
Servo servo2;
AF_DCMotor motor(1);

void TaskBlink( void *pvParameters );
void TaskAnalogRead( void *pvParameters );
//void TaskAnalogRead( void *pvParameters );


void setup() {

#ifdef DEBUG
	Serial.begin(9600);
	Serial.println("Debug mode is active");
#endif


	  servo1.attach(9);
	  servo2.attach(10);
	  motor.setSpeed(200);
	  motor.run(RELEASE);

	xTaskCreate(
	    TaskBlink
	    ,  (const portCHAR *)"Blink"   // A name just for humans
	    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
	    ,  NULL
	    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
	    ,  NULL );

	  xTaskCreate(
	    TaskAnalogRead
	    ,  (const portCHAR *) "AnalogRead"
	    ,  128  // Stack size
	    ,  NULL
	    ,  1  // Priority
	    ,  NULL );
}

void Rotate_Servos(short int RequestedX, short int RequestedY)
{
	int X_position = RequestedX;
	int Y_position = RequestedY;

	if((X_position > 0) && (Y_position > 0))
	{
		for (i=0; i <= X_position; i++) {
			    servo1.write(i);
			    delay(3);
		}
		for (i=0; i <= Y_position; i++) {
					    servo2.write(i);
					    delay(3);
		}
	}
	else if((X_position > 0) && (Y_position < 0))
	{
		for (i=0; i <= X_position; i++) {
			    servo1.write(i);
			    delay(3);
		}
		for (i=0; i <= Y_position; i--) {
					    servo2.write(i);
					    delay(3);
		}
	}
	else if((X_position < 0) && (Y_position > 0))
	{
		for (i=0; i <= X_position; i--) {
			    servo1.write(i);
			    delay(3);
		}
		for (i=0; i <= Y_position; i++) {
					    servo2.write(i);
					    delay(3);
		}
	}
	else if((X_position < 0) && (Y_position < 0))
	{
		for (i=0; i <= X_position; i--) {
			    servo1.write(i);
			    delay(3);
		}
		for (i=0; i <= Y_position; i--) {
					    servo2.write(i);
					    delay(3);
		}
	}
}

int Calc_Servo_Angle(short int JoyPos_X, short int JoyPos_Y)
{
	int retVal;
	short int Calc_X;
	short int Calc_Y;

	retVal = Rotate_Servos(Calc_X,Calc_Y);

	return retVal;
}



void loop() {

#ifndef DEBUG
	Serial.println("Debug mode is active");
#endif


}

//----------------------------------------------------------------------------15ms Task
void Task15ms(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  for (;;)
  {
	  //Put executables here/////
#ifdef DEBUG
	//Serial.println("This is a tickcount message from 15ms task");
#endif

	  //motor.run(FORWARD);
	    //servo2.write(-50);
	    //servo2.write(50);
	  //Rotate_Servo1();
	  //Rotate_Servo2();
    // print out the value you read:

    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}

//----------------------------------------------------------------------------1000ms Task
void Task1000ms(void *pvParameters)  // This is a task.
{
  (void) pvParameters;



  for (;;) // A Task shall never return or exit.
  {
#ifdef DEBUG
	Serial.println("This is a tickcount message from 1000ms task");
#endif


   //do something here
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
  }
}




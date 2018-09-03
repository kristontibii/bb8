#include "pin_definitions.h"
#include "read_digital_pins.h"
#include "Communication.h"
#include "oled.h"
#include "read_digital_pins.h"
#include <TaskScheduler.h>
#include <XBee.h>

Scheduler runner;
XBee xbee = XBee();
unsigned int payload[] = { 0, 0 };
Tx16Request tx = Tx16Request(0x1874, payload, sizeof(payload));


void setup() {
  runner.startNow();

}

void loop() {
    runner.execute();

}

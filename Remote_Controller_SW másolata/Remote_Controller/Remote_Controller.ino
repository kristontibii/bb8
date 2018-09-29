#include "pin_definitions.h"
#include "read_digital_pins.h"
#include "Communication.h"
#include "oled.h"
#include "read_digital_pins.h"
#include <TaskScheduler.h>


Scheduler runner;





void setup() {
  runner.startNow();

  pinMode(A0, INPUT);

}

void loop() {
    runner.execute();

}

#include "Applications/Xbee/Com.h"
#include "Libraries/XBee-Arduino_library/0.6.0/Xbee.h"

uint8_t payload[] = { 0, 0, 0, 0 };



void flashLed(int pin, int times, int wait) {

    for (int i = 0; i < times; i++) {
      digitalWrite(pin, HIGH);
      delay(wait);
      digitalWrite(pin, LOW);

      if (i + 1 < times) {
        delay(wait);
      }
    }
}





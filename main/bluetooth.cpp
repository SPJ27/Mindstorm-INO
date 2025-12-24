#include <Arduino.h>
#include "bluetooth.h"

char bluetooth_read() {
  if (Serial.available()) {
    return Serial.read();
  }
  return NULL; 
}

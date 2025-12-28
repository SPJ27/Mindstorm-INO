#include <Arduino.h>
#include "bluetooth.h"

String bluetooth_read() {
  if (Serial.available()) {
    return Serial.read();
  }
  return NULL; 
}

#include <Arduino.h>
#include "bluetooth.h"

String bluetooth_read() {
  if (Serial.available()) {
    return Serial.readStringUntil('\n'); // read full command
  }
  return ""; // return empty String
}

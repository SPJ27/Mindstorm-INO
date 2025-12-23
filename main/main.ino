#include "motors.h"
#include "bluetooth.h"

char val = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = bluetooth_read();
  if (val == '1') {
    move(1, FORWARD, 255);
    move(2, FORWARD, 255);
  } else if (val == '2') {
    move(1, BACKWARD, 255);
    move(2, BACKWARD, 255);
  }
}

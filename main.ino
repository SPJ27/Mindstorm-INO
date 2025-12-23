#include "motors.h"
#include "bluetooth.h"

char val = 0;

void setup() {
  Serial.begin(9600);
  // move(1, BACKWARD, 255);
  // move(2, BACKWARD, 255);
  // delay(2000);
  // move(2, BRAKE);

}

void loop() {
  bluetooth_read();
  Serial.println(val);
}

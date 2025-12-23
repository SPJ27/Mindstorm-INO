#include "motors.h"
#include "bluetooth.h"
#include "distance.h"
char val = 0;

void setup() {
  Serial.begin(9600);
  setup_distance();

}

void loop() {
  // val = bluetooth_read();
  // if (val == '1') {
  //   move(1, FORWARD, 255);
  //   move(2, FORWARD, 255);
  // } else if (val == '2') {
  //   move(1, BACKWARD, 255);
  //   move(2, BACKWARD, 255);
  // }
  Serial.println(find_distance());

}

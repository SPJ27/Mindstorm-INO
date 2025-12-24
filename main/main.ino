/*
Some basic functions ->
1. Motor control
 - move(motor number(1,2,3), direction(FORWARD, BACKWARD, BRAKE), speed(0 - 255))
2. Bluetooth
 - bluetooth_read() -> returns NULL or a char
3. Distance (Ultrasonic Sensor)
 - setup_distance() = use this in void setup() function
 - find_distance() = returns distance in float 
*/

#include "motors.h"
#include "bluetooth.h"
#include "distance.h"
#include "servo_control.h"

char val = 0;
void setup() {
  Serial.begin(9600);
  servo_use(A);
  // move(M1, BACKWARD, 255);
  // move(M2, FORWARD, 255);
  // setup_distance();
}

void loop() {
  // val = bluetooth_read();
  // if (val == '1') {
  //   move(M1, FORWARD, 255);
  //   move(M2, FORWARD, 255);
  // } else if (val == '2') {
  //   move(M1, BACKWARD, 255);
  //   move(M2, BACKWARD, 255);
  // }
  // Serial.println(find_distance());
  // servo_rotate(140);
  for (int i = 0; i < 180; i++) {
    servo_rotate(A, i);
  }
}

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

char val = 0;

void setup() {
  Serial.begin(9600);
  setup_distance();

}

void loop() {
  // val = bluetooth_read();
  // f (val == '1') {
  //   move(1, FORWARD, 255);
  //   move(2, FORWARD, 255);
  // } else if (val == '2') {
  //   move(1, BACKWARD, 255);
  //   move(2, BACKWARD, 255);
  // }i
  Serial.println(find_distance());

}

#include <Arduino.h>
#include <Servo.h>
#include "servo_control.h"
#include "mindstorm.h"

static Servo servo_1;
static Servo servo_2;

void servo_use(uint8_t port) {
  if (port == SA) {
    servo_1.attach(SA);
  } else if (port == SB) {
    servo_2.attach(SB);
  }
}

void servo_rotate(uint8_t port, int angle) {
  angle = constrain(angle, 0, 180);

  if (port == SA) {
    servo_1.write(angle);
  } else if (port == SB) {
    servo_2.write(angle);
  }
}

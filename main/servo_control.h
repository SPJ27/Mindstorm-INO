#include <Servo.h>

Servo myservo;

void servo_use(uint8_t port) {
  myservo.attach(port);
}

void servo_rotate(uint8_t port, int val) {
  myservo.write(val);
}
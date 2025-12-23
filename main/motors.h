#include "AFMotor_R4.h"

AF_DCMotor motor_1(1);  // Create motor on M1
AF_DCMotor motor_2(2);  // Create motor on M1
AF_DCMotor motor_3(3);  // Create motor on M1
AF_DCMotor motor_4(4);  // Create motor on M1


void move(char motor_number, uint8_t motor_direction, int motor_speed = NULL) {
  if (motor_number == 1) {
    motor_1.run(motor_direction);
    motor_1.setSpeed(motor_speed);
  } else if (motor_number == 2) {
    motor_2.run(motor_direction);
    motor_2.setSpeed(motor_speed);
  } else if (motor_number == 3) {
    motor_3.run(motor_direction);
    motor_3.setSpeed(motor_speed);
  } else if (motor_number == 4) {
    motor_4.run(motor_direction);
    motor_4.setSpeed(motor_speed);
  }
}
#include "AFMotor_R4.h"

int M1 = 1;
int M2 = 2;
int M3 = 3;
int M4 = 4;

AF_DCMotor motor_1(1);  // Create motor on M1
AF_DCMotor motor_2(2);  // Create motor on M2
AF_DCMotor motor_3(3);  // Create motor on M3
AF_DCMotor motor_4(4);  // Create motor on M4


void move(uint8_t motor_number, uint8_t motor_direction, int motor_speed = NULL) {
  if (motor_number == M1) {
    motor_1.run(motor_direction);
    motor_1.setSpeed(motor_speed);
  } else if (motor_number == M2) {
    motor_2.run(motor_direction);
    motor_2.setSpeed(motor_speed);
  } else if (motor_number == M3) {
    motor_3.run(motor_direction);
    motor_3.setSpeed(motor_speed);
  } else if (motor_number == M4) {
    motor_4.run(motor_direction);
    motor_4.setSpeed(motor_speed);
  }
}
#include <AFMotor_R4.h>
#include "motors.h"
#include "mindstorm.h"

AF_DCMotor m1(1);
AF_DCMotor m2(2);
AF_DCMotor m3(3);
AF_DCMotor m4(4);

void move(uint8_t motor, uint8_t direction, uint8_t speed) {
  AF_DCMotor* m = nullptr;

  if (motor == M1) m = &m1;
  else if (motor == M2) m = &m2;
  else if (motor == M3) m = &m3;
  else if (motor == M4) m = &m4;

  if (m) {
    m->setSpeed(speed);
    m->run(direction);
  }
}

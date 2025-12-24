#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#include <Arduino.h>

void servo_use(uint8_t port);
void servo_rotate(uint8_t port, int angle);

#endif

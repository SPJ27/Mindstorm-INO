#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>


void setup_button(uint8_t port);
int detect_action(uint8_t port);

#endif
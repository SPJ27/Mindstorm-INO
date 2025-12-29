#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

void start_display();
void write_text(int line, String text);
void clear_display();

#endif
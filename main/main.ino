#include "mindstorm.h"
#include "buttons.h"
#include "bluetooth.h"
#include "display.h"


void setup() {
  start_display();
  setup_modules();
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
}

void loop() {
  if (detect_action(5)==1) Serial.println(("Up"));
  if (detect_action(6)==1) Serial.println(("Down"));
}
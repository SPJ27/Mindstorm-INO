#include "mindstorm.h"
#include "display.h"
#include "buttons.h"

void setup() {
  Serial.begin(9600);
  start_display();
  setup_button(A);
}

void loop() {
  write_text(0, "String(detect_action(A))");
}
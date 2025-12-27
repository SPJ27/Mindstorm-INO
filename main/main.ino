#include "mindstorm.h"
#include "buttons.h"
#include "bluetooth.h"
#include "display.h"


void setup() {
  start_display();
  setup_modules();
}

void loop() {
    if(detect_action())
}
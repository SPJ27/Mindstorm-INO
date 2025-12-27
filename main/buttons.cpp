#include "mindstorm.h"
#include "buttons.h"

int get_pin(uint8_t port) {
  if (port == A) return A0;
  if (port == B) return A2;
  if (port == C) return 2;
  return port
}

int detect_action(uint8_t port) {
  int pin;
  pin = get_pin(port);
  int btn_state = digitalRead(pin);
  const int last_state = btn_state;

  while (btn_state == last_state) {
    btn_state = digitalRead(pin);
  }
  if (last_state == 0 && btn_state == 1) return 0;
  else if (last_state == 1 && btn_state == 0) return 1;
  else return -1;
}
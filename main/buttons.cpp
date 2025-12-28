#include "buttons.h"
#include "mindstorm.h"


static int lastStateA = HIGH;
static int lastStateB = HIGH;
static int lastStateC = HIGH;
static int lastStateD = HIGH;


int detect_action(int pin) {
  int currentState = digitalRead(pin);
  int *lastState;

  if (pin == 5) lastState = &lastStateA;
  else if (pin == 6) lastState = &lastStateB;
  else if (pin == 7) lastState = &lastStateC;
  else if (pin == 8) lastState = &lastStateD;
  else return 0;

  if (*lastState == HIGH && currentState == LOW) {
    *lastState = currentState;
    return 1; 
  }

  *lastState = currentState;
  return 0;
}

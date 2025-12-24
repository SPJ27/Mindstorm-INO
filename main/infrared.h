

int outPin;

int check_infrared(uint8_t port) {
  if (port == A) {
    outPin = A0;
  } else if (port == B) {
    outPin = A2;
  } else if (port == C) {
    outPin = 2;
  }
  return digitalRead(outPin);
}
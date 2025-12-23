char incomingValue;

char bluetooth_read() {
  if (Serial.available() > 0) {
    incomingValue = Serial.read();
    return incomingValue;
  }
  return 0;
}

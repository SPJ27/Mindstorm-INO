#include "distance.h"
#include "mindstorm.h"

float find_distance(uint8_t port) {
  int trigPin, echoPin;

  if (port == A) { trigPin = A1; echoPin = A0; }
  else if (port == B) { trigPin = A3; echoPin = A2; }
  else if (port == C) { trigPin = 4;  echoPin = 2; }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long d = pulseIn(echoPin, HIGH);
  if (d == 0) return -1;
  return (d * 0.0343) / 2;
}

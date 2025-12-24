#include "distance.h"
#include "mindstorm.h"


void setup_distance(uint8_t port) {
  if (port == A) {

    pinMode(A0, OUTPUT);
    pinMode(A1, INPUT);
  } else if (port == B) {

    pinMode(A2, OUTPUT);
    pinMode(A3, INPUT);
  } else if (port == C) {

    pinMode(2, OUTPUT);
    pinMode(4, INPUT);
  };
}

float find_distance(uint8_t port) {
  int trigPin, echoPin;

  if (port == A) { trigPin = A0; echoPin = A1; }
  else if (port == B) { trigPin = A2; echoPin = A3; }
  else if (port == C) { trigPin = 2;  echoPin = 4; }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long d = pulseIn(echoPin, HIGH);
  if (d == 0) return -1;
  return (d * 0.0343) / 2;
}

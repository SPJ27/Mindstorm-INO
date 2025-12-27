#include "mindstorm.h"
#include <Arduino.h>


const int M1 = 1;
const int M2 = 2;

const int A = 1;
const int B = 2;
const int C = 3;

const int SA = 3;
const int SB = 7;

const int FRONT = 1;
const int BACK = 2;

void setup_modules() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
}
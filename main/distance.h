int trigPin;
int echoPin;

unsigned long duration;
float distance;


void setup_distance(uint8_t port) {
  if (port == A){
    trigPin = A0;
    echoPin = A1;
  }
  else if (port == B){
    trigPin = A2;
    echoPin = A3;
  }
  else if (port == C){
    trigPin = 2;
    echoPin = 4;
  }
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float find_distance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  return distance;
  delay(100);
}


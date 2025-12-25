#include "mindstorm.h"
#include "display.h"
#include "distance.h"

void setup() {
  Serial.begin(9600);
  setup_distance(A);
  start_display();
}

void loop() {
  write_text(0, "Distance: "+ String(find_distance(A)) + " cm");
  delay(1000);
}
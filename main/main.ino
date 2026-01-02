#include "mindstorm.h"
#include "buttons.h"
#include "bluetooth.h"
#include "display.h"
#include "motors.h"
#include "distance.h"
#include "infrared.h"

#define PROGRAM_COUNT 4

String sample_programs[PROGRAM_COUNT] = {
  "1. Bluetooth Car",
  "2. Distance Measure",
  "3. Line Follower",
  "4. BT Text Reader",
};

int currentSelection = 0;
int nextSelection = 1;
bool programRunning = false;
bool loadingScreen = true;

void bluetooth_car() {
  write_text(0, "Bluetooth Car");


  while (detect_action(8) == 0) {
    write_text(1, bluetooth_status());
    String val = bluetooth_read();
    if (val == "1") {
      move(M1, FRONT, 255);
      move(M2, FRONT, 255);
    } else if (val == "2") {
      move(M1, BACK, 255);
      move(M2, BACK, 255);
    } else if (val == "3") {
      move(M1, BACK, 255);
      move(M2, FRONT, 255);
    } else if (val == "4") {
      move(M1, FRONT, 255);
      move(M2, BACK, 255);
    }
  }
}

void distance_measurement() {
  write_text(0, "Distance Mode");
  write_text(1, "Running...");
  while (detect_action(8) == 0) {
    float d = find_distance(A);
    write_text(1, String(d) + " cm");
    delay(300);
  }
}

void line_follower() {

  write_text(0, "Line Follower");
  write_text(1, "Running...");
  while (detect_action(8) == 0) {
    int left = check_infrared(A);
    int right = check_infrared(B);
    if (left == 0 && right == 0) {
      move(M1, FRONT, 150);
      move(M2, FRONT, 150);
    } else if (left == 1) {
      move(M1, BACK, 100);
      move(M2, FRONT, 150);
    } else if (right == 1) {
      move(M1, FRONT, 150);
      move(M2, BACK, 100);
    }
  }
}

void bluetooth_text_reader() {
  write_text(0, "BT Text Mode");
  write_text(1, "Running...");
  while (detect_action(8) == 0) {
    String text = bluetooth_read();
    if (text.length() > 0) {
      write_text(1, text);
    }
  }
}

void setup() {
  setup_modules();
  start_display();
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
}

void loop() {
  if (loadingScreen) {
    write_text(0, "Mindstorm INO");
    write_text(1, "Press OK");
    if (detect_action(7) == 1) {
      clear_display();
      loadingScreen = false;
    }
  } else {
    if (!programRunning) {
      if (detect_action(5) == 1) {
        currentSelection++;
        if (currentSelection >= PROGRAM_COUNT)
          currentSelection = 0;
      }
      if (detect_action(6) == 1) {
        currentSelection--;
        if (currentSelection < 0)
          currentSelection = PROGRAM_COUNT - 1;
      }
      nextSelection = currentSelection + 1;
      if (nextSelection >= PROGRAM_COUNT)
        nextSelection = 0;
      write_text(0, sample_programs[currentSelection]);
      write_text(1, sample_programs[nextSelection]);
      if (detect_action(7) == 1) {
        programRunning = true;
        clear_display();
        switch (currentSelection) {
          case 0: bluetooth_car(); break;
          case 1: distance_measurement(); break;
          case 2: line_follower(); break;
          case 3: bluetooth_text_reader(); break;
        }
        programRunning = false;
        write_text(0, "Exited Program");
        write_text(1, "Back to Menu");
        delay(1000);
      }
    }
  }
}

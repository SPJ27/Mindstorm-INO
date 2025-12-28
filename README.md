# Arduino MindStorm Library

*A LEGO Mindstorms–style abstraction layer for Arduino*

The **MindStorm Arduino Library** makes Arduino programming feel like LEGO Mindstorms.
Instead of dealing with raw pins, delays, and low-level code, you interact with **motors, sensors, display, Bluetooth, and servos** using simple, high-level functions.

This library is designed for:

* Educational robots
* Custom programmable bricks
* Low-cost LEGO Mindstorms alternatives
* Beginners learning robotics the **right way**

---

## Library Structure

```text
mindstorm.h     // Core library (REQUIRED)
display.h       // LCD display functions
bluetooth.h    // Bluetooth communication
infrared.h     // Infrared sensor
motors.h       // DC motor control
distance.h     // Ultrasonic distance sensor
servo.h        // Servo motor control
```

---

## ⚠️ IMPORTANT (Must Read)

### `mindstorm.h` is **MANDATORY**

You **must include** `mindstorm.h` in every project.

###  `setup_modules()` is REQUIRED

You **must call** `setup_modules()` inside `void setup()`.

Without this:

* Pins won’t be configured
* Modules won’t work
* Behavior is undefined

Correct usage:

```cpp
#include "mindstorm.h"

void setup() {
  setup_modules();   // REQUIRED
}

void loop() {
}
```

---

## Core Constants (From `mindstorm.h`)

### Motors

```cpp
M1, M2
```

### Sensor Ports

```cpp
A, B, C
```

### Servo Ports

```cpp
SA, SB
```

### Motor Directions

```cpp
FRONT
BACK
```

---

## Display Module (`display.h`)

Used for LCD-based text output (like Mindstorms screen).

### Functions

```cpp
void start_display();
void write_text(int line, String text);
```

### Example

```cpp
#include "display.h"

start_display();
write_text(0, "Hello Robot");
write_text(1, "MindStorm OS");
```

`line` can be `0` or `1` (for 16x2 LCD).

---

## Bluetooth Module (`bluetooth.h`)

Used to receive commands wirelessly from a phone or computer.

### Function

```cpp
String read_bluetooth();
```

### Example

```cpp
String cmd = read_bluetooth();

if (cmd == "F") {
  move(M1, FRONT, 150);
}
```

---

## Infrared Module (`infrared.h`)

Used for IR obstacle detection or line sensing.

### Function

```cpp
int check_infrared(uint8_t port);
```

### Example

```cpp
if (check_infrared(A) == 1) {
  move(M1, BACK, 100);
}
```

Returns a digital value (0 or 1).

---

## Motor Module (`motors.h`)

Controls DC motors with speed and direction.

### Function

```cpp
void move(uint8_t motor, uint8_t direction, uint8_t speed);
```

### Example

```cpp
move(M1, FRONT, 200);
move(M2, FRONT, 200);
```

`speed` range: `0–255`

---

## Distance Module (`distance.h`)

Used with ultrasonic sensors to measure distance.

### Function

```cpp
float find_distance(uint8_t port);
```

### Example

```cpp
float d = find_distance(B);

if (d < 10) {
  move(M1, BACK, 120);
}
```

Distance is returned in **centimeters**.

---

## Servo Module (`servo.h`)

Used for arms, grippers, camera mounts, etc.

### Functions

```cpp
void servo_use(uint8_t port);
void servo_rotate(uint8_t port, int angle);
```

### Example

```cpp
servo_use(SA);
servo_rotate(SA, 90);
```

Angle range: `0–180`

---

## Full Example (Mini Mindstorms Program)

```cpp
#include "mindstorm.h"
#include "motors.h"
#include "distance.h"

void setup() {
  setup_modules();
}

void loop() {
  float dist = find_distance(A);

  if (dist < 15) {
    move(M1, BACK, 150);
    move(M2, BACK, 150);
  } else {
    move(M1, FRONT, 200);
    move(M2, FRONT, 200);
  }
}
```


---

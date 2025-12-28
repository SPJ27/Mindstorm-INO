# Arduino MindStorm Library

*A LEGO Mindstorms–style abstraction layer for Arduino*

The **MindStorm Arduino Library** makes Arduino programming feel like LEGO Mindstorms.
Instead of dealing with raw pins, delays, and low-level code, you interact with **motors, sensors, display, Bluetooth, and servos** using simple, high-level functions.

### Why Mindstorm INO?

I built **Mindstorm INO** because I wanted a faster and simpler way to build robots without redesigning the hardware every time.  
It also helps me experiment freely, switch projects quickly, and learn robotics in a hands-on way.  
I plan on to make it more compact by designing PCB boards.

---

## Hardware Instructions  
### Building the **Mindstorm INO Intelligent Brick**

This section explains the hardware required and how to wire the components to build your own **Mindstorm INO–style programmable brick** using Arduino.

## Components Required

| Quantity | Component |
|--------:|-----------|
| 1 | Arduino UNO / Nano |
| 1 | L293D Motor Driver IC |
| 4 | Push Buttons (UP / DOWN / OK / BACK) |
| 1 | HC-05 Bluetooth Module |
| 1 | I2C LCD Display (16×2) |
| 1+ | Breadboard(s) |
| — | Jumper Wires |

---

## Circuit Diagram

Below is the complete wiring diagram for the Mindstorm INO Intelligent Brick:

<p align="center">
  <img src="https://raw.githubusercontent.com/SPJ27/Mindstorm-INO/refs/heads/main/Circuit%20Diagram.png" width="600">
</p>

---

## Notes

- The **L293D** is used to control DC motors (M1 and M2).
- The **I2C LCD** minimizes pin usage and simplifies wiring.
- Push buttons are configured using **INPUT_PULLUP** (no external resistors required).
- The **HC-05 Bluetooth module** enables wireless control and communication.
- This circuit is designed to be **modular**, similar to LEGO Mindstorms.

---

## Important Tips

- Double-check power connections before turning on the circuit.
- Use a common **GND** for all modules.
- If motors behave erratically, add decoupling capacitors near the L293D.
- Keep Bluetooth RX/TX wiring correct (crossed).

---

## Next Step

Once the hardware is assembled:
1. Upload the **Mindstorm INO firmware**
2. Power on the system
3. Navigate programs using the button-based menu
4. Run Mindstorms-style robot programs

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
// #include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(0x27, 16, 2);

// char *list[] = { "1. Run Code", "2. View Code", "3. Load Code", "4. Open Settings", "5. Manage Device", "6. Exit Code"};

// int val = 0;
// int button_value = 0;

// int item_1 = -1;
// int item_2 = 0;

// void setup() {
//   pinMode(2, INPUT);

//   Serial.begin(9600);
//   lcd.init();
//   lcd.backlight();
//   lcd.setCursor(0, 0);
//   lcd.print("Mindstorm INO");
//   lcd.setCursor(0, 1);
//   lcd.print("By Saksham Jain");
// }


// void loop() {
//   button_value = digitalRead(2);
//   if (val == 0 && button_value == 1) {
//     val = 1;
//             item_1++; item_2++;

//     lcd.clear();
//     lcd.setCursor(0,0 );
//     lcd.print(">");
//     lcd.setCursor(2,0 );
//     lcd.print(list[item_1]);
//     lcd.setCursor(0,1);
//     lcd.print(list[item_2]);

//     Serial.println("clicked");
//   } else if (button_value == 0) {
//     val = 0;
//   }
// }
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte customChar[] = {
  B00100,
  B00110,
  B10101,
  B01110,
  B00110,
  B01101,
  B10110,
  B00100
};

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, customChar);
  lcd.home();
  lcd.write(0);
}

void loop() { }

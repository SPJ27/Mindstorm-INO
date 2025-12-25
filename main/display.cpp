#include "mindstorm.h"
#include "display.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void start_display() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void write_text(int line, String text) {
  lcd.setCursor(0, line);
  lcd.print(text);s
}

void clear_display(){
  lcd.clear();
}
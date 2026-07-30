#include <Arduino.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd (12,11,5,4,3,2);//(RS,E,D4,D5,D6,D7)
void setup() {
    lcd.begin(16,2);
    lcd.setCursor(5,0);
    lcd.print("Ghida");
}
void loop() {
 
  //delay(15000);
  //lcd.clear();
}


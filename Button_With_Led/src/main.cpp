#include <Arduino.h>

int sw = 2;
int redled = 8;
int yellowled=9;
int greenled=10;
int spk = 11;

void setup() {
  pinMode(sw, INPUT_PULLUP);
  pinMode(redled, OUTPUT);
  pinMode(spk, OUTPUT);
}

void loop() {

  int state = digitalRead(sw);
  if (state == 0) {
    digitalWrite(redled, HIGH);
    tone(spk,550,100);
    delay(150);
    digitalWrite(yellowled, HIGH);
    tone(spk,400,100);
    delay(150);
    digitalWrite(greenled, HIGH);
    tone(spk,200,100);
  } 

  else {
    digitalWrite(redled, LOW);
    noTone(spk);
  }
}
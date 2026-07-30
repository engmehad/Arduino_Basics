#include <Arduino.h>
const int sw=8;
const int x_axis=A0;
const int y_axis=A1;
const int redLed=2;
const int yellowLed=3;
const int blueLed=4;
const int greenLed=5;
const int allLed[4]={redLed,yellowLed,blueLed,greenLed};
void setup() {
  Serial.begin(9600);
  pinMode(sw, INPUT_PULLUP);
  pinMode(redLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(blueLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
}

void loop() {
 int x=analogRead(x_axis);
 int y=analogRead(y_axis);
 int button=digitalRead(sw);
 Serial.print("X: ");
 Serial.print(x);
 Serial.print("\tY: ");
 Serial.print(y);
 Serial.print("\tButton: ");
 Serial.println(button);

 for(int i=0;i<4;i++){
      digitalWrite(allLed[i],LOW);
 }
 delay(1000);
 if(y>900){
  digitalWrite(redLed,HIGH);
 }
 else if(y<200){
  digitalWrite(yellowLed,HIGH);
 }
 else if(x>900){
  digitalWrite(blueLed,HIGH);
}
else if(x<100){
  digitalWrite(greenLed,HIGH);
}

if(digitalRead(sw)==LOW){
    for(int i=0;i<4;i++){
      digitalWrite(allLed[i],HIGH);
    }
    delay(1000);
      for(int i=0;i<4;i++){
      digitalWrite(allLed[i],LOW);
    }
}
  delay(100);
}


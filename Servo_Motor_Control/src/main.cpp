#include<Arduino.h>
#include <Servo.h>
const int trigPin = 8;
const int echoPin = 9;
const int servoPin = 2;

Servo myServo; 
const int thresholdDistance = 20; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0);
  Serial.begin(9600);
}

void loop() {
  
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= thresholdDistance) {
    myServo.write(180); 
    delay(500); 
  } else {
    myServo.write(0);
  }

  delay(100);
}




/*
#include <Arduino.h>
#include <Servo.h>
Servo myservo;
void setup() {
  myservo.attach(9);
}

void loop() {
  myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
}



*/



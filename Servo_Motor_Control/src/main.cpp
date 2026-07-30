#include<Arduino.h>
#define trigPin 3
#define echoPin 2

#define greenLed 6
#define yellowLed 5
#define redLed 4
#define buzzerPin 7

long duration;
float distance;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzerPin,OUTPUT);
}

void loop() {

  // إرسال نبضة للحساس
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // قراءة المسافة
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2.0;
  Serial.print("Distance:");
  Serial.print(distance);
  Serial.println(" cm");
  // التحكم بالليدات

  // بعيد
  if (distance > 20) {

    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    noTone(buzzerPin);

  }

  // متوسط
  else if (distance > 10 && distance <= 20) {

    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, LOW);
    tone(buzzerPin,400);
    delay(100);
    noTone(buzzerPin);

  }

  // قريب جداً
  else {

    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    tone(buzzerPin,1000);

  }

  delay(500);
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
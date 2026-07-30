#include <Arduino.h>
int D1=200;
int D2=300;
#define redLed 8
#define blueLed 7
unsigned long T1=0,T2=0,T3=0;
bool s1=0,s2=0;
void setup(){
pinMode(blueLed,OUTPUT);
pinMode(redLed,OUTPUT);
}
void loop(){
T1=millis();
if (T1 > T2 + D1) {
    s1 = !s1;
    T2 = T1;
}
if (T1 > T3 + D2) {
    s2 = !s2;
    T3 = T1;
}
digitalWrite(blueLed, s1);
digitalWrite(redLed, s2);
}


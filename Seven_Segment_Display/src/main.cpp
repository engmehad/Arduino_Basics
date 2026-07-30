#include<Arduino.h>
#include"SevSeg.h"
SevSeg sevseg;
void setup(){
byte numDigits=4;
byte digitalPin[]={2,3,4,5};
byte segmentPin[]={6,7,8,9,10,11,12};
sevseg.begin(COMMON_CATHODE,numDigits,digitalPin,segmentPin);
sevseg.setBrightness(100);
}
void loop(){
sevseg.setNumber(2006);
sevseg.refreshDisplay();

}
#include "Adafruit_Soundboard.h"
#define ACT 13  //define/connect the active sound pin in your arduino 13 pin
#define ZERO 3  //define/connect the 0 sound pin to your arduino 3 pin

// Sharp IR code for Robojax.com
#include <SharpIR.h>

#define IR A0 // define signal pin
#define model 1080 // used 1080 because model GP2Y0A21YK0F is used

//detect the distance being detected by the sensor
int proxDistance = 0;

// the maximum distance to trigger a reaction.
//check your treshhold any time you reupload your code
const int proxThresh = 400;

SharpIR sharp(IR, model);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ACT, INPUT); //setup your ACT input
  pinMode(ZERO, OUTPUT); //setup your zero output
  
  digitalWrite(ZERO, HIGH); //turn your zero pin OFF
}

void loop() {
//int dist = sharp.distance();
  delay(500);   

proxDistance = analogRead(A0);
Serial.println(proxDistance); //this number gets smaller the more distance there is

if(proxDistance > proxThresh){
  digitalWrite(ZERO, LOW); //turn your zero pin ON/play sound from pin 0
  delay(1000);  //delay by one millisecond
  digitalRead(ACT); //turn your ACT pin ON (this turns on all the sound pins and allows sound to be played)
  delay(100); //delay by one millisecond
  }

  else{
    digitalWrite(ZERO, HIGH);
    digitalRead(ACT);
    }

//    digitalWrite(ZERO, LOW); //turn your zero pin ON/play sound from pin 0
//    delay(1000);  //delay by one millisecond
//    
//   while(digitalRead(ACT) == LOW) {  //turn your ACT pin ON (this turns on all the sound pins and allows sound to be played)
//    Serial.println("ZERO"); delay(1); }
//    //int act = digitalRead(ACT);
//    //if(act) { Serial.println("ZERO"); delay(1); }
//    
//
//    digitalWrite(ZERO, HIGH); //turn your zero pin OFF
//    delay(1000); //delay for a millisecond
}

// Sharp IR code for Robojax.com
#include <SharpIR.h>
#define model 1080
#define IR A0 // define signal pin
SharpIR sharp(IR, model);

//Include sound library
#include "Adafruit_Soundboard.h"
#define ACT 13  //define/connect the active sound pin in your arduino 13 pin
#define ONE 3  //define/connect the 1 sound pin to your arduino 3 pin

// the maximum distance in inches to trigger a reaction.
//check your treshhold any time you reupload your code
const int proxThresh = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //setup the pins in your soundboard
  pinMode(ACT, INPUT); //setup your ACT input
  pinMode(ONE, OUTPUT); //setup your zero output
  digitalRead(ACT == 0); //turn your act pin off
  digitalWrite(ONE, HIGH); //turn your zero pin OFF
}


void loop() {
  // put your main code here, to run repeatedly:
  int dist = sharp.distance(); //refers to this library https://github.com/guillaume-rico/SharpIR/blob/master/SharpIR.cpp
  Serial.println(dist);        //to make tha data a recognizable distance in cm
  delay(100);


  if (dist <= proxThresh) {
    digitalWrite(ONE, LOW); //turn your zero pin ON/play sound from pin 0
    //delay(1000);  //delay by one millisecond
    digitalRead(ACT); //turn your ACT pin ON (this turns on all the sound pins and allows sound to be played)
    //delay(1000); //delay by one millisecond
  }

  else {
    digitalWrite(ONE, HIGH);
    digitalRead(ACT == 0); 
  }
}

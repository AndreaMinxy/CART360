#include <SharpIR.h>

/*code taken from Robojax
 * buzzer code and circuit found here: https://create.arduino.cc/projecthub/SURYATEJA/use-a-buzzer-module-piezo-speaker-using-arduino-uno-89df45
 * adding a buzzwer sound effect based on the proximity. Do I need to have an analog read here?
 * Sharp IR (infrared) distance measurement module for Arduino
 * Measures the distance in cm.

 * Watch the video https://youtu.be/GL8dkw1NbMc

 *  * 

Original library: https://github.com/guillaume-rico/SharpIR

Updated by by Ahmad Nejrabi for Robojax.com
on Feb 03, 2018 at 07:34 in Ajax, Ontario, Canada
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * 
 /*
/*




 */
  // Sharp IR code for Robojax.com
#include <SharpIR.h>

#define IR A0 // define signal pin
#define model 1080 // used 1080 because model GP2Y0A21YK0F is used

//detect the distance being detected by the sensor
int proxDistance = 0;

// the maximum distance to trigger a reaction.
//check your treshhold any time you reupload your code
const int proxThresh = 250;

//set buzzer to pin 9
const int buzzer = 9;

// Sharp IR code for Robojax.com
// ir: the pin where your sensor is attached
// model: an int that determines your sensor:  1080 for GP2Y0A21Y
//                                            20150 for GP2Y0A02Y
//                                            430 for GP2Y0A41SK   
/*
2 to 15 cm GP2Y0A51SK0F  use 1080
4 to 30 cm GP2Y0A41SK0F / GP2Y0AF30 series  use 430
10 to 80 cm GP2Y0A21YK0F  use 1080
10 to 150 cm GP2Y0A60SZLF use 10150
20 to 150 cm GP2Y0A02YK0F use 20150
100 to 550 cm GP2Y0A710K0F  use 100550

 */

SharpIR SharpIR(IR, model);
void setup() {
    // Sharp IR code for Robojax.com
 Serial.begin(9600);
 Serial.println("Robojax Sharp IR  ");
 pinMode(buzzer, OUTPUT);
}

void loop() {
    // Sharp IR code for Robojax.com
    delay(500);   

proxDistance = analogRead(A0);
Serial.println(proxDistance); //this number gets smaller the more distance there is


//this segment of code was the original robojax proximity code
/*unsigned long: range from 0 to 4,294,967,295
//  unsigned long startTime=millis();  // takes the time before the loop on the library begins
//
//  int dis=SharpIR.distance();  // this returns the distance to the object you're measuring- what is the unit of measurement
//
//  // Sharp IR code for Robojax.com
//
//  Serial.print("Mean distance: ");  // returns it to the serial monitor
//  Serial.println(dis);
//  //Serial.println(analogRead(A0));
//  unsigned long endTime=millis()-startTime;  // the following gives you the time taken to get the measurement
// Serial.print("Time taken (ms): ");
// Serial.println(endTime);  
//     // Sharp IR code for Robojax.com*/



 //if the sensor's threshhold is breached, output a sound

  if(proxDistance > proxThresh){
  tone(buzzer, 1000); // Send 1KHz sound signal...
  //delay(1000);        // ...for 1 sec
    }
    else{

      noTone(buzzer);
      
      }
 
     
}

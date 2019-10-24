/*we want to code a pair of plushies to recreate 
the up/down and right/left arrow keys for a digital 
storytelling game*/ 


//include the joystick and keyboard libraries
#include <Joystick.h>
#include <Keyboard.h>

//set up the key characters
char upKey = KEY_UP_ARROW;
char downKey = KEY_DOWN_ARROW;
char rightKey = KEY_RIGHT_ARROW;
char leftKey = KEY_LEFT_ARROW;

Joystick_ Joystick;
int hugPin = A0 ;  // define analog port A0 for the plushie sensor to connect
int value = 0;    //set value to 0
int threshold = 320; //we're gonna have to play with the threshhold here


/*how do we combine the joystick library and the keyboard library 
to create a controller?*/
void setup() {
Joystick.begin(); //set up the joystick
Keyboard.begin(); //set up the replacement keyboard in this case: plushies

}

void loop() {
  //read the values of x and y axis to otput the value of the position of the plushie
  int rawX = analogRead(A1);
  int rawY = analogRead(A2);
  
  /*when you hug your plushie, you're pressign down on the keys and 
  the direction you move is the arrow key, then you eliminate the other 
  arrow keys from the equation*/

  /*if(value > threshold){ //if the plushie is being squeezed above the threshold
   //turn the joystick on
  }*/

  //how do you map the position of the plushie?
  /*how do I create a output based on a combination of the yx axis 
  and the left, right, up and down arrow keys*/
  Joystick.setYAxis(rawY);
  Joystick.setXAxis(rawX);
  delay(20)

}

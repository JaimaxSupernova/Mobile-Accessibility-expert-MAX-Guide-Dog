
/* ********THIS CODE IS NOT COMPLETE --- WILL NOT RUN ******  */ 

#include <Servo.h>
// declare Servo object variable called "servo"
Servo esc;
Servo steer;

int escPin = 22;
int steerPin = 21;

// global variable to represent direction of servo rotation
int direction;

// global variables (constants) to represent esc rotation
const int COUNTER_CLOCKWISE = 1000;
const int STOPPED = 1500;
const int CLOCKWISE = 2000;

// Global variables (constants) to represent steer direction
const int LEFT = 0;
const int STRAIGHT = 90;
const int RIGHT = 180;

// turn on servo motor
esc.attach(escPin);
steer.attach(steerPin);
// turn off servo motor
//esc.detach();
//steer.detach();

void setup(){
}

void loop(){
  /* ESC MOTOR CONTROL */
  // rotate counter-clockwise full-speed
esc.writeMicroseconds(COUNTER_CLOCKWISE);
// rotation stopped
esc.writeMicroseconds(STOPPED);
// rotate clockwise full-speed
esc.writeMicroseconds(CLOCKWISE);


  /* STEER MOTOR CONTROL */
steer.writeMicroseconds(LEFT);
steer.writeMicroseconds(STRAIGHT);
steer.writeMicroseconds(RIGHT);


}











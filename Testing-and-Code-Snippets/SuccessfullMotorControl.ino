//Written by Ane

#include <Servo.h>

#define escPin 22 // Output pin used
#define steerPin 21


int pos = 0;
int speed;


Servo esc;
Servo steer;


// global variable to represent direction of servo rotation
int carDirection;

// global variables (constants) to represent esc rotation
const int BACKWARDS = 1000;
const int STOPPED = 1500;
const int FORWARD = 2000;

// Global variables (constants) to represent steer direction
const int LEFT = 0;
const int STRAIGHT = 90;
const int RIGHT = 180;



void setup(){
}

void loop(){
  // turn on servo motor
esc.attach(escPin);
steer.attach(steerPin);
// turn off servo motor
//esc.detach();
//steer.detach();

/*testing*/

steer.write(RIGHT);
esc.writeMicroseconds(FORWARD);
Serial.print(steer.read());
delay(5000);
steer.write(STRAIGHT);
esc.writeMicroseconds(STOPPED);
Serial.print(steer.read());
delay(5000);
steer.write(LEFT);
esc.writeMicroseconds(BACKWARDS);
Serial.print(steer.read());
delay(5000);


 

//steer.writeMicroseconds(RIGHT);
//delay(5000);
//  /* ESC MOTOR CONTROL */
//  // rotate counter-clockwise full-speed
//esc.writeMicroseconds(FORWARD);
//// rotation stopped
//esc.writeMicroseconds(STOPPED);
//// rotate clockwise full-speed
//esc.writeMicroseconds(FORWARD);
//delay(5000);

  /* STEER MOTOR CONTROL */
//steer.writeMicroseconds(RIGHT);
//steer.writeMicroseconds(STRAIGHT);
//steer.writeMicroseconds(RIGHT);
//esc.writeMicroseconds(BACKWARDS);
//delay(5000);

}

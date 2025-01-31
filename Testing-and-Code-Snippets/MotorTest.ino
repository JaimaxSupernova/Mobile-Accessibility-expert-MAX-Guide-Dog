#include <Servo.h>

#define esc 22 // Output pin used

Servo myservo;      // create servo object to control a servo
int pos = 0;
int speed;

void setup() {
myservo.attach(esc);
pos = map(speed, 0, 1023, 0, 180);
myservo.write(pos);
  
  
  
  //myservo.attach(esc, 400, 2600); // Minimum and maximum pulse width (in µs) to go from 0° to 180°.

}

void loop() {

}

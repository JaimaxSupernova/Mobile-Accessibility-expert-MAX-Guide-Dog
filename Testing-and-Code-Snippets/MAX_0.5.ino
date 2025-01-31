//Marley Hayward
//30/10/23
//MAX Guide Dog V 0.1
//A program to automate the dog movement and object avoidance

//Include statements.
#include <Servo.h>
//Defining the pins and explanation.

/*
Power: 5v from Mbed to breadboard.
Ground: Ground from Mbed to other side of breadboard.

Esc Motor (Drive Motor):
GPIO Pin = 22.

Servo Motor (Steer Motor):
GPIO Pin = 21;

Accelerometer:

I2C Display:

Ultrasonic Sensor One (FL) (Front-Left Sensor):
5v = breadboard.
Ground = breadboard.
Trig = GPIO Pin 3
Echo = GPIO Pin 4

Ultrasonic Sensor Two (FM) (Front-Middle Sensor):
5v = breadboard.
Ground = breadboard.
Trig = GPIO Pin 5
Echo = GPIO Pin 6

Ultrasonic Sensor Three (FR) (Front-Right Sensor):
5v = breadboard.
Ground = breadboard.
Trig = GPIO Pin 8
Echo = GPIO Pin 9


Ultrasonic Sensor Five (RL) (Rear-Left Sensor):
5v = breadboard.
Ground = breadboard.
Trig = GPIO Pin 10
Echo = GPIO Pin 11

Ultrasonic Sensor Four (RR) (Rear-Right Sensor):
5v = breadboard.
Ground = breadboard.
Trig = GPIO Pin 12
Echo = GPIO Pin 13

Other variables used to track 
pitpin (potentiometer pin) = 28;
val (steering angle...i think);
*/

/*Pin/Device Declaration.*/
Servo esc;
Servo steer;

/*Variables Declaration*/
int duration;
long distance;
int direction;

// global variables (constants) to represent esc rotation
const int FORWARD = 2000;
const int REVERSE = 1000;
const int STOPPED = 1500;

// Global variables (constants) to represent steering angles.
const int RIGHT = 180;
const int LEFT = 0;
const int CENTER = 90;

int potpin = 28; //On board potentiometer - not used.
int val;

//Motors
int escMotorPin = 22;
int steerMotorPin = 21;

//Sensors
int sensorFLTrig = 3;
int sensorFLEcho = 4;
int sensorFMTrig = 5;
int sensorFMEcho = 6;
int sensorFRTrig = 8;
int sensorFREcho = 9;
int sensorRLTrig = 10;
int sensorRLEcho = 11;
int sensorRRTrig = 12;
int sensorRREcho = 13;

//Sensor Values
long frontLeftDistance;
long frontMiddleDistance;
long frontRightDistance;
long rearRightDistance;
long rearLeftDistance;

/*Movement Methods*/

void carStartup() { //Method to straigten the cars wheels on boot.
  steer.write(CENTER);
  esc.writeMicroseconds(STOPPED);
}

void moveForward() { 
  steer.write(CENTER);
  esc.writeMicroseconds(FORWARD);
}

void moveBackwards() {
  steer.write(CENTER);
  esc.writeMicroseconds(REVERSE);
}

void stopCar() {
  steer.write(CENTER);
  esc.writeMicroseconds(STOPPED);
}

void moveRight() {
  steer.write(RIGHT);
  esc.writeMicroseconds(FORWARD);
}

void moveLeft() {
  steer.write(LEFT);
  esc.writeMicroseconds(FORWARD);
}

/*Other methods used for interaction*/



void setup() {
  
  /*Sensors*/
  pinMode(sensorFLTrig, OUTPUT);
  pinMode(sensorFLEcho, INPUT);

  pinMode(sensorFMTrig, OUTPUT);
  pinMode(sensorFMEcho, INPUT);

  pinMode(sensorFRTrig, OUTPUT);
  pinMode(sensorFREcho, INPUT);

  pinMode(sensorRLTrig, OUTPUT);
  pinMode(sensorRLEcho, INPUT);

  pinMode(sensorRRTrig, OUTPUT);
  pinMode(sensorRREcho, INPUT);

}

void loop() {

  /*Now adding our code to take sensor input and make the car turn based on its surroundings.*/

  /*READING FROM FRONT-LEFT SENSOR*/
  digitalWrite(sensorFLTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorFLTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorFLTrig, LOW);

  duration = pulseIn(sensorFLEcho, HIGH);

  frontLeftDistance = duration * 0.034 / 2;

  //Serial.print("Distance FL: ");
  //Serial.println(frontLeftDistance);

  /*READING FROM FRONT-MIDDLE SENSOR*/
  digitalWrite(sensorFMTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorFMTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorFMTrig, LOW);

  duration = pulseIn(sensorFMEcho, HIGH);

  frontMiddleDistance = duration * 0.034 / 2;

  //Serial.print("Distance FM: ");
  //Serial.println(frontMiddleDistance);

  
  /*READING FROM FRONT-RIGHT SENSOR */
  digitalWrite(sensorFRTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorFRTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorFRTrig, LOW);

  duration = pulseIn(sensorFREcho, HIGH);

  frontRightDistance = duration * 0.034 / 2;

  //Serial.print("Distance FR: ");
  //Serial.println(frontRightDistance);

  /*READING FROM REAR-LEFTT SENSOR */
  digitalWrite(sensorRLTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorRLTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorRLTrig, LOW);

  duration = pulseIn(sensorRLEcho, HIGH);

  rearLeftDistance = duration * 0.034 / 2;

  //Serial.print("Distance RL: ");
  //Serial.println(rearLeftDistance);
  
  /*READING FROM REAR-RIGHT SENSOR */
  digitalWrite(sensorRRTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorRRTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorRRTrig, LOW);

  duration = pulseIn(sensorRREcho, HIGH);

  rearRightDistance = duration * 0.034 / 2;

  //Serial.print("Distance RR: ");
  //Serial.println(rearRightDistance);



}

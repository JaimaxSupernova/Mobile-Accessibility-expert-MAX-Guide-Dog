# Test Report

*This part of the report covers the testing of individual components of the project to ensure robustness of the system.*

## Motor Tests

### Motor Movement and Speed Test
*The Motors movement speed was tested using the code below:*

```cpp
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
```

*This code aimed to test the control of the cars speed, however it did not work as intended. The car moved when intended, however the speed could not be varied.*

### Car Direction Control Testing

*The code below was used for testing the cars direction control. This meant making the car turn right, left and also the cars ability to reverse.*

```cpp
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
}
```
*This test confirmed that we could successfully control the direction of the car reliably. It went as expected.*

### Ultrasonic Sensor Testing

*Testing was conducted to test if the sensors returned a valid value for distance using this code:*
```cpp
// Pico/Mbed bridge - Sonar sensor example
// Copyright CSEE Jon W


// pins

const int trigPin = 10; //Can also use Pin 4
const int echoPin = 11; //Can also use Pin 5

// variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  

}
```

*This successfully printed the distance to the serial monitor and was therefore used in the final code*

### Testing Control of Direction Depending on Sensor Distance

*Finally, we tested that the sensors could successfully cause the car to steer so that the car could actively avoid obstacles using the code below:*
```
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

int duration;
int distance;

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


void setup(){
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
//esc.writeMicroseconds(STOPPED);
Serial.print(steer.read());
delay(5000);
steer.write(LEFT);
esc.writeMicroseconds(BACKWARDS);
Serial.print(steer.read());
delay(5000);




/*READING FROM FRONT-LEFT SENSOR*/
  digitalWrite(sensorFLTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorFLTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorFLTrig, LOW);

  duration = pulseIn(sensorFLEcho, HIGH);

  frontLeftDistance = duration * 0.034 / 2;

  Serial.print("Distance FL: ");
  Serial.println(frontLeftDistance);

  /*READING FROM FRONT-MIDDLE SENSOR*/
  digitalWrite(sensorFMTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorFMTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorFMTrig, LOW);

  duration = pulseIn(sensorFMEcho, HIGH);

  frontMiddleDistance = duration * 0.034 / 2;

  Serial.print("Distance FM: ");
  Serial.println(frontMiddleDistance);
                      if(frontMiddleDistance < 20) 
                            {
                              esc.writeMicroseconds(STOPPED);
                              Serial.println("STOPPING");
                              delay(5000);
                             
                            }
  
  /*READING FROM FRONT-RIGHT SENSOR */
  digitalWrite(sensorFRTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorFRTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorFRTrig, LOW);

  duration = pulseIn(sensorFREcho, HIGH);

  frontRightDistance = duration * 0.034 / 2;

  Serial.print("Distance FR: ");
  Serial.println(frontRightDistance);

  /*READING FROM REAR-LEFTT SENSOR */
  digitalWrite(sensorRLTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorRLTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorRLTrig, LOW);

  duration = pulseIn(sensorRLEcho, HIGH);

  rearLeftDistance = duration * 0.034 / 2;

  Serial.print("Distance RL: ");
  Serial.println(rearLeftDistance);
  
  /*READING FROM REAR-RIGHT SENSOR */
  digitalWrite(sensorRRTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorRRTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorRRTrig, LOW);

  duration = pulseIn(sensorRREcho, HIGH);

  rearRightDistance = duration * 0.034 / 2;

  Serial.print("Distance RR: ");
  Serial.println(rearRightDistance);


}
```
*This test was successful and therefore was the skeleton to the functionality of our final program.*


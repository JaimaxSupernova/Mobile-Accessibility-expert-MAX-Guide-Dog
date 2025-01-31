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
Trig = GPIO Pin 6
Echo = GPIO Pin 7

Ultrasonic Sensor Four (RR) (Rear-Right Sensor):
5v = breadboard.
Ground = breadboard.
Trig = GPIO Pin 9
Echo = GPIO Pin 10

Ultrasonic Sensor Five (RL) (Rear-Left Sensor):
5v = breadboard.
Ground = breadboard.
Trig = GPIO Pin 14
Echo = GPIO Pin 15

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

int potpin = 28;
int val;

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


/*Monitoring*/


void setup() {

  /*Motion*/
  pinMode(26, OUTPUT);
  digitalWrite(26, HIGH);
  esc.attach(22);
  steer.attach(21);
  esc.write(90);
  steer.write(90);
  delay(5000);
  digitalWrite(26, LOW);

  

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
  //Reading the values from the Potentiometer.
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 180); /*the value is being mapped - steering angle is between 0 (left) and 180 (Right).
  esc.write(val);                  Writing this value to the esc motor to control the speed relative to the steering angle.*/
  steer.write(val);
  delay(15); 
  /*Now adding our code to take sensor input and make the car turn based on its surroundings.*/

  /*READING FROM FRONT-LEFT SENSOR*/
  digitalWrite(sensorFLTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorFLTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorFLTrig, LOW);

  duration = pulseIn(sensorFLEcho, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance FL: ");
  Serial.println(distance);

  /*READING FROM FRONT-MIDDLE SENSOR*/
  digitalWrite(sensorFMTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorFMTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorFMTrig, LOW);

  duration = pulseIn(sensorFMEcho, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance FM: ");
  Serial.println(distance);

  
  /*READING FROM FRONT-RIGHT SENSOR */
  digitalWrite(sensorFRTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorFRTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorFRTrig, LOW);

  duration = pulseIn(sensorFREcho, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance FR: ");
  Serial.println(distance);

  /*READING FROM REAR-LEFTT SENSOR */
  digitalWrite(sensorRLTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorRLTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorRLTrig, LOW);

  duration = pulseIn(sensorRLEcho, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance RL: ");
  Serial.println(distance);
  
  /*READING FROM REAR-RIGHT SENSOR */
  digitalWrite(sensorRRTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorRRTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorRRTrig, LOW);

  duration = pulseIn(sensorRREcho, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance RR: ");
  Serial.println(distance);
  

  /*Monitoring*/


}

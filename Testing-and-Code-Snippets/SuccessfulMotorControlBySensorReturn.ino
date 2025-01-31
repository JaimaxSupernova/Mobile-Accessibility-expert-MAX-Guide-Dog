// Marley's sensor code combined with Ane's motor control code

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

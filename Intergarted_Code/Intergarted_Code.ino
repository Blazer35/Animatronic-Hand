#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define THRESHOLD 200

Servo myservo;
int EMG_PIN = A0; //A0 emg sensor
const int sensorPin1 = A2; //A2 hall sensor
const int sensorPin2 = A3; //A3 hall sensor
const int sensorPin3 = A4; //A4 hall sensor
int sensorReading1;
int sensorReading2;
int sensorReading3;
#define PCA9685_FREQ 50
int position;
int hallthreshold;
  Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();    
  uint8_t servonum = 5; //PCA
  const uint16_t SERVO_MIN_PULSE_WIDTH = 500;
  const uint16_t SERVO_MAX_PULSE_WIDTH = 2500;
#define SERVO_MIN_ANGLE 0
#define SERVO_MAX_ANGLE 180
Adafruit_PWMServoDriver pwmDriver;

void setup(){
  Serial.begin(9600);
  myservo.write(180);  // Closed claw.
  position = 180;
  pwm.begin();  //PCA
   pwmDriver.setPWMFreq(PCA9685_FREQ);

  
Serial.println("1. Bottle"); 
Serial.println("2. Ball");
Serial.println("3. Hand");
}

void loop1(){
Serial.println("What would you like to hold? ");
while (Serial.available() == 0) {
}
int menuChoice = Serial.parseInt(); 
switch (menuChoice) { 
case 1: 
hallthreshold == 300;
 break; 
case 2: 
hallthreshold == 495;
break; 
case 3: 
hallthreshold == 400;
//Serial.println(); 
break; 
default: 
Serial.println("Please choose a valid selection"); 
}
}
 
void hall()
{
  sensorReading1 = analogRead(sensorPin1);
    Serial.print("Hall 1 = ");
    Serial.println(sensorReading1); // the raw analog reading
    // We'll have a few threshholds, qualitatively determined

  delay(100);
}

void loop(){
int value = analogRead(EMG_PIN);

if(value > THRESHOLD)
{ 
   openClaw(); 
}
  else {
   closeClaw();
  }
   Serial.println(value); 
}

  void openClaw() {

      for (; position < 130;  position++) {
      int servoPulseWidth = map(SERVO_MAX_ANGLE, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
      pwmDriver.setPWM(0, 0, servoPulseWidth);
     if(analogRead(sensorPin1) > hallthreshold )
       break;
      }
       for (; position < 130;  position++) {
      int servoPulseWidth1 = map(SERVO_MAX_ANGLE, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
      pwmDriver.setPWM(1, 0, servoPulseWidth1);
       if(analogRead(sensorPin2) > hallthreshold )
       break;
       }

      for (; position < 130;  position++) {
      int servoPulseWidth2 = map(SERVO_MAX_ANGLE, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
      pwmDriver.setPWM(2, 0, servoPulseWidth2);
      
      
      int servoPulseWidth3 = map(SERVO_MAX_ANGLE, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
      pwmDriver.setPWM(3, 0, servoPulseWidth3);

    
      int servoPulseWidth4 = map(SERVO_MAX_ANGLE, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
      pwmDriver.setPWM(4, 0, servoPulseWidth4);
      if(analogRead(sensorPin3) > hallthreshold )
       break;
      }
    }
  
  void closeClaw() {
    // Set all servo motors to 0 degrees (default position)
    for (int servoNum = 0; servoNum < 5; servoNum++) {
      int servoPulseWidth = map(SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
      pwmDriver.setPWM(servoNum, 0, servoPulseWidth);
    }
    delay(2000);
  }

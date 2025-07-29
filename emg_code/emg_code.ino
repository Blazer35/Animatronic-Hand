#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include<Servo.h>

Adafruit_PWMServoDriver mi = Adafruit_PWMServoDriver();

#define servoMIN 100
#define servoMAX 600

Servo myservo;

int sensorPin = A2;


int sensorReading;

int sensorReading1;
int emgPin = A1;
float emgValue ;
int threshold =25                              0;
int hallthreshold = 533;
int toggle = 0;
int sensorPin1 = A2;
int position, i,hall;

void setup() {
  Serial.begin(9600);
  mi.begin();
  mi.setPWMFreq(60);
}

void loop() {
  emgValue = analogRead(emgPin);
  hall=analogRead(sensorPin1);
  Serial.println(emgValue);  
  delay(400);

  if (threshold < emgValue)
  {
   if (toggle == 1)
    {
      openclaw();
    }
    else
    {
      closeclaw();
      delay(5000);
    }
    toggle = !toggle;
    
  }
  
}

void openclaw()
{
   mi.setPWM(0, 0, servoMAX);
   mi.setPWM(2, 0, servoMAX); 
   mi.setPWM(4, 0, servoMAX);
   mi.setPWM(6, 0, servoMAX);
   mi.setPWM(8, 0, servoMAX);
  
}

void closeclaw()
{
    mi.setPWM(0, 0, servoMIN);
    mi.setPWM(2, 0, servoMIN);
    mi.setPWM(4, 0, servoMIN);
    mi.setPWM(6, 0, servoMIN);
    mi.setPWM(8, 0, servoMIN);
}

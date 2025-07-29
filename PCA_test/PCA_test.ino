#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver mi = Adafruit_PWMServoDriver();

#define servoMIN 100
#define servoMAX 600
int position;

Servo myservo;

void setup(){
  mi.begin();
  mi.setPWMFreq(60);
}

void loop(){
    delay(1000);
  
   mi.setPWM(0, 0, servoMAX);
   mi.setPWM(2, 0, servoMAX); 
   mi.setPWM(4, 0, servoMAX);
   mi.setPWM(6, 0, servoMAX);
   mi.setPWM(8, 0, servoMAX);

    delay(5000);

    mi.setPWM(0, 0, servoMIN);
    mi.setPWM(2, 0, servoMIN);
    mi.setPWM(4, 0, servoMIN);
    mi.setPWM(6, 0, servoMIN);
    mi.setPWM(8, 0, servoMIN);

    delay(3000);


}

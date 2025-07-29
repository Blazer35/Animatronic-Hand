#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
 
Servo servothumb;         
Servo servoindex;         
Servo servomiddle;
Servo servoring;
Servo servopinky;
int position;

Adafruit_PWMServoDriver mi = Adafruit_PWMServoDriver();

#define servoMIN 100
#define servoMAX 600
Servo myservo;

 
char number[50];
char c;
int state = 0;
String myStringRec;
int stringCounter = 0;
bool stringCounterStart = false;
String myRevivedString;
int stringLength = 6;
 
int servoPinky,servoMiddle,servoIndex,servoThumb,servoRing;
int myVals[] ={0,0,0,0,0} ;
 
int myButton= 1;
bool portable;
 
void setup() {
  mi.begin();
  mi.setPWMFreq(60);
  delay(500);
  if (myButton == 0){portable = false;}
  else {portable = true;}
   
}
 
void loop() {
 
 delay(500);
receiveData();
if (servoPinky ==0){  mi.setPWM(8, 0, servoMAX);}else{mi.setPWM(8, 0, servoMIN);}
if (servoIndex ==0){  mi.setPWM(2, 0, servoMAX);}else{mi.setPWM(2, 0, servoMIN);}
if (servoMiddle ==0){  mi.setPWM(4, 0, servoMAX);}else{mi.setPWM(4, 0, servoMIN);}
if (servoThumb ==0){  mi.setPWM(0, 0, servoMAX);}else{mi.setPWM(0, 0, servoMIN);}
if (servoRing ==0){  mi.setPWM(6, 0, servoMAX);}else{mi.setPWM(6, 0, servoMIN);}


 
}
 

 
 
void receiveData() {
  int i = 0;
  while (Serial.available()) {
   char c = Serial.read();
   
    if (c == '$') {
      stringCounterStart = true;
    }
    if (stringCounterStart)
    {
      if (stringCounter < stringLength)
      {
        myRevivedString = String(myRevivedString+c);
        stringCounter++;
      }
      if (stringCounter >= stringLength) {
        stringCounter = 0; 
        servoThumb = myRevivedString.substring(1,2).toInt();
        servoIndex = myRevivedString.substring(2,3).toInt();
        servoMiddle = myRevivedString.substring(3,4).toInt();
        servoRing = myRevivedString.substring(4,5).toInt();
        servoPinky = myRevivedString.substring(5,6).toInt();
        myRevivedString = "";
        stringCounterStart = false;
      }
    }
  }
}

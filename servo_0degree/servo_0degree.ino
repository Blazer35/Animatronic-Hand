#include<Servo.h>
Servo mi;
int pos =0;
void setup()
{
  mi.attach(9);
}
void loop()
{
  
  {
    mi.write(0);
    delay(30); 
  }
 
  
  
}

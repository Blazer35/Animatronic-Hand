int emgPin = A1;
float emgValue ;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  
  emgValue = analogRead(emgPin);
  Serial.println(emgValue);
  delay(500);
} 

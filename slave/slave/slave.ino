#include <Wire.h>
   double x;
void setup() {
  // put your setup code here, to run once:

  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Received temp : ");   
  Serial.println(x);   

delay(100);
}

void receiveEvent(double howmany){

 x = Wire.read();
 
  
  }

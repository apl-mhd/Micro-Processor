#include <dht.h>
#include<Wire.h>

dht DHT;
int echoPin = 11;
int trigPin = 12;

void setup() {
  // put your setup code here, to run once:

  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

   DHT.read11(13);

  Serial.print("Temperature : ");
  Serial.println(DHT.temperature);


 Wire.beginTransmission(4);
 Wire.write((int) DHT.temperature);
 Wire.endTransmission();
 delay(300);


 pinMode(trigPin, OUTPUT);
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 pinMode(echoPin,INPUT);

 long duration = pulseIn(echoPin, HIGH);
   long distance = ( duration * 0.034) /2;
   double colorRatio  = (distance/11) * 2.5;  // convert to 255 ration
   Serial.print("Distance ");
   Serial.println(distance);


Wire.beginTransmission(5);
//Wire.write((int) distance);
Wire.write((int)colorRatio);
Wire.endTransmission();
delay(300);

 

}

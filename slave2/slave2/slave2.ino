#include<Wire.h>

int rcvData;


int redLED =13;
int blueLED = 11;
int r = 0;
int b = 255;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(5);
  Wire.onReceive(receiveEvent);
   pinMode(redLED, OUTPUT);
 
  pinMode(blueLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Slave 2");
  
  Serial.println(rcvData);
  //delay(400);

   //double a  = (rcvData/11) * 2.5;
      //int x = (int) a;
      //x = rcvData;
      r = 0 + rcvData;
      b = 255 - rcvData ;

  analogWrite(redLED, r );
 analogWrite(blueLED,b);
  


}


void receiveEvent(int a){

    rcvData = Wire.read();
  
  }


  

#include <SoftwareSerial.h>
int ledState = LOW;
 unsigned long previousMillis = 0;
void blinkWithoutDelay(int ledPin, int delayTime){
  
  unsigned long currentMillis = millis();
  if (currentMillis-previousMillis>=0){
    if(ledState == LOW){
      ledState = HIGH;
    }
    else ledState = LOW;
  }
  digitalWrite(ledPin,ledState);
}

char state;
int speedState;

char moveForward = 'F';
char moveBackward = 'B';
char moveRight = 'R';
char moveLeft = 'L';
char stopVehicle = 'S';
char hornOn = 'V';
char hornOff = 'v';
char frontLightOn = 'W';
char frontLightOff = 'w';
char backLightOn = 'U';
char backLightOff = 'u';
char trafficatorOn = 'X';
char trafficatorOff = 'x';

// Port = new Serial(this, "COM7", 9600);
int forwardPin1 = 7;
int forwardPin2 = 3;

int backwardPin1 = 6;
int backwardPin2 = 2;

//int enablePin1 = 10;
int enablePin = 9;

int currentSpeed = 255;

int brakeLight = 11;
int reverseLight = 8;

int mainFrontLight = 4;
int trafficatorMain = 5;
int trafficatorBlue = 12;
int trafficatorRed = 10;
int hornPin = 13;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

//pinMode(9, OUTPUT);'
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);

analogWrite(enablePin,currentSpeed);
//analogWrite(enablePin2,currentSpeed);


}

void loop() {

if(Serial.available()>0){
  state=Serial.read();
}  
 if(state == '0'||state == '1'||state == '2'||state == '3'||state == '4'||state == '5'||state == '6'||state == '7'||state == '8'||state == '9'){
  speedState = state-'0';
  currentSpeed = 255*speedState/10;
  
analogWrite(enablePin,currentSpeed);
//analogWrite(enablePin2,currentSpeed);

}
else if(state == 'q'){
  analogWrite(enablePin,255);
//analogWrite(enablePin2,255);
}

  
   if(state == 'F'){
  digitalWrite(reverseLight, LOW);
  digitalWrite(brakeLight, LOW);
  
 // digitalWrite(sideLightLeft, LOW);
 // digitalWrite(sideLightRight, LOW);
  
  digitalWrite(forwardPin1, HIGH);
  digitalWrite(forwardPin2, HIGH);

  digitalWrite(backwardPin1, LOW);
  digitalWrite(backwardPin2, LOW);
   }
   if(state=='B'){
  digitalWrite(reverseLight, HIGH);
 // digitalWrite(sideLightLeft, LOW);
  //digitalWrite(sideLightRight, LOW);

  digitalWrite(backwardPin1, HIGH);
  digitalWrite(backwardPin2, HIGH);

  digitalWrite(forwardPin1, LOW);
  digitalWrite(forwardPin2, LOW);
    }
    
  if(state=='R'){
 // blinkWithoutDelay(sideLightRight, 300);
  digitalWrite(reverseLight, LOW);
  digitalWrite(brakeLight, LOW);
  
  
  
  digitalWrite(forwardPin1, HIGH);
  digitalWrite(backwardPin2, HIGH);

  digitalWrite(forwardPin2, HIGH);
  digitalWrite(backwardPin1, LOW);
  }
  
  if(state=='L'){
 // blinkWithoutDelay(sideLightLeft, 300);
//  digitalWrite(sideLightLeft, LOW);
 // digitalWrite(sideLightRight, LOW);
    digitalWrite(reverseLight, LOW);

  
  digitalWrite(forwardPin2, HIGH);
  
  digitalWrite(backwardPin2, LOW);
  digitalWrite(backwardPin1, HIGH);
  digitalWrite(forwardPin1, HIGH);
  
  
 }
    if (state == stopVehicle){
       digitalWrite(reverseLight, HIGH);
       digitalWrite(brakeLight, HIGH);
    //   digitalWrite(sideLightLeft, LOW);
      // digitalWrite(sideLightRight, LOW);
       
       digitalWrite(forwardPin1, HIGH);
       digitalWrite(backwardPin2, HIGH);

       digitalWrite(forwardPin2, HIGH);
       digitalWrite(backwardPin1, HIGH);
      
    }
    if (state == backLightOn){
      digitalWrite(brakeLight, HIGH);
    }
    if (state == backLightOff){
      digitalWrite(brakeLight, LOW);
    }
    if (state == frontLightOn){
      digitalWrite(mainFrontLight, HIGH);
    }
    if (state == frontLightOff){
      digitalWrite(mainFrontLight, LOW);
    }
    if(state == trafficatorOn){
      blinkWithoutDelay(trafficatorMain,300);
      blinkWithoutDelay(trafficatorRed,200);
      blinkWithoutDelay(trafficatorBlue,200);
    }
    if(state == trafficatorOff){
      digitalWrite(trafficatorMain, LOW);
      digitalWrite(trafficatorBlue, LOW);
      digitalWrite(trafficatorRed, LOW);
      
    }
    if (state == hornOn){
      digitalWrite(hornPin, HIGH);
    }
    if (state == hornOff){
      digitalWrite(hornPin, LOW);
    }


}

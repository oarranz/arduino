#include <Servo.h>
Servo myServo;

const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

int knockVal;
int switchVal;

const int quietKnock = 1;
const int loudKnock = 5;

boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  myServo.attach(9);
  pinMode(switchPin,INPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  Serial.begin(9600);
  digitalWrite(greenLed,HIGH);
  myServo.write(0);
  Serial.println("La caja está abierta");
}

void loop() {
  if(locked == false){
    switchVal = digitalRead(switchPin);
    if(switchVal == HIGH){
      locked = true;
      digitalWrite(greenLed,LOW);
      digitalWrite(redLed,HIGH);
      myServo.write(90);
      Serial.println("La caja está cerrada");
      delay(1000);
    }
  }
  if(locked == true){
    knockVal = analogRead(piezo);
    if(numberOfKnocks<3 && knockVal>0){
      if(checkForKnock(knockVal)==true){        
        numberOfKnocks++; 
      }
      Serial.print(3-numberOfKnocks);
      Serial.println(" golpes más para abrir"); 
      delay(500);
    }    
    if(numberOfKnocks>=3){
      locked=false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed,HIGH);
      digitalWrite(redLed,LOW);
      Serial.println("La caja está abierta");
      numberOfKnocks=0;
    }
  }
}

boolean checkForKnock(int value){  
  if(value >= quietKnock && value <= loudKnock){
    digitalWrite(yellowLed,HIGH);
    delay(50);
    digitalWrite(yellowLed,LOW);
    Serial.print("Valor de golpe válido: ");
    Serial.println(value);
    return true;
  } 
  else {
    Serial.print("Valor de golpe no válido: ");
    Serial.println(value);
    return false;    
  }
}

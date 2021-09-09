const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 3000;
int outputVoltage = HIGH;
int i = 1;

void setup() {  
  for (int x = 2; x<8; x++){
    pinMode(x,OUTPUT);
  }
  pinMode(switchPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - previousTime > interval){
    previousTime = currentTime;    
    digitalWrite(led,outputVoltage);  
    led = led + i;  
    if (led > 7){
      outputVoltage = LOW;
      led--;
      i = -1;      
    }
    if (led < 2){
      outputVoltage = HIGH;
      i = 1;
      led++;
    }
   } 

  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState){
    for (int x = 2; x<8; x++){
      digitalWrite(x,LOW);
    }
    led = 2;
    previousTime = currentTime;
  }

  prevSwitchState = switchState;

  Serial.print("Valor de la variable previousTime: ");
  Serial.println(previousTime);
  Serial.print("Valor de la variable switchState: ");
  Serial.println(switchState);
  Serial.print("Valor de la variable prevSwitchState: ");
  Serial.println(prevSwitchState);
  delay(200);
}

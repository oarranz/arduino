const int potPin = A0;
int potValue;
void setup() {
  Serial.begin(9600);
  pinMode(potPin,INPUT);
}

void loop() {
 potValue = analogRead(potPin) / 4;
 //Serial.print("El valor decimal llegit es: ");
 //Serial.println(potValue);
 //Serial.print("El caràcter enviat és: ");
 Serial.write(potValue); 
 //Serial.print("\n");
 delay(1);
}

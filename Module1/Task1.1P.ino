int sensorPin=2;
int ledPin=3;
void setup()
{
  Serial.begin(9600);
  
  pinMode(sensorPin, INPUT);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
  digitalWrite(sensorPin, LOW);
  delay(50);
}

void loop()
{
  if(digitalRead(sensorPin)==HIGH){
    Serial.println("HIGH");
    digitalWrite(ledPin,HIGH);
    delay(50);
   
  } else if(digitalRead(sensorPin)==LOW){
    Serial.println("LOW");
    digitalWrite(ledPin,LOW);
    delay(50);
  }
    
  delay(50);
  
 
}
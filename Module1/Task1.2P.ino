int sensorPin=2;
int ledPin=3;
uint8_t ledState=LOW;

void setup()
{
  Serial.begin(9600);
  
  pinMode(sensorPin, INPUT);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
  digitalWrite(sensorPin, LOW);
  attachInterrupt(digitalPinToInterrupt(sensorPin),runAction,FALLING);
  
  delay(50);
}

void loop()
{
Serial.println(digitalRead(sensorPin));
    
    
  delay(1000);
  
 
}
void runAction(){
  Serial.println("High");
   digitalWrite(ledPin,HIGH);
 delay(10000);
   digitalWrite(ledPin,LOW);
  
    
  
    
 
  

  
  
}

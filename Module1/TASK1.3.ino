int sensorPin=2;
int ledPin=5;

int buttonPin=3;
 int count=LOW;
void setup()
{
  Serial.begin(9600);
  
  pinMode(sensorPin, INPUT);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
  digitalWrite(sensorPin, LOW);
  pinMode(buttonPin,INPUT);
 attachInterrupt(digitalPinToInterrupt(buttonPin),pressAction,CHANGE);
 attachInterrupt(digitalPinToInterrupt(sensorPin),runAction,RISING);
  
  

}

void loop()
{
  Serial.println(digitalRead(buttonPin));
  
 
 delay(1000);
}
void runAction(){
  Serial.println("High");
   digitalWrite(ledPin,HIGH);
 
  
}
void pressAction(){
  Serial.println("Button Pressed");
  if(count==LOW){
    digitalWrite(ledPin,HIGH);
    count=HIGH;
  }
  
    
  
}

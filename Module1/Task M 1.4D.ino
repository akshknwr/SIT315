int sensorLeft=10;
int sensorRight=11;
int ledPin=3;
int ledpin2=4;
int ledBlue=5;

int buttonPin=9;
 
void pciSetup(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}
void setup()
{
  
  int i;
 
// set pullups, if necessary
  for (i=3; i<=11; i++)
      digitalWrite(i,LOW);  // by default pinmode(pin, input)
 
  //setting LEDs for each sensor's input's notification
  pinMode(ledPin,OUTPUT);  
  pinMode(ledpin2,OUTPUT);
  pinMode(ledBlue,OUTPUT);
  // enabling interrupts for pins...
  pciSetup(sensorLeft);
  pciSetup(sensorRight);
  pciSetup(buttonPin);
  pciSetup(ledBlue);
  

}

void loop()
{
  //all functions are handled via timer interrupts
  
}

    
  

 
ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
 {    
    
  if(digitalRead(sensorLeft)==HIGH){
    
     digitalWrite(ledBlue,HIGH);
   
  } else{
     digitalWrite(ledBlue,LOW);
   // digitalWrite(ledpin2,LOW);
  }
   
  if(digitalRead(buttonPin)==HIGH){
    //digitalWrite(ledBlue,HIGH);
     digitalWrite(ledpin2,HIGH);
  } else{
    digitalWrite(ledpin2,LOW);
  }
  
  if(digitalRead(sensorRight)==HIGH){
    digitalWrite(ledPin,HIGH);
  } else{
    digitalWrite(ledPin,LOW);}
  
  
      
  
  
  
      
  
 }
 

 


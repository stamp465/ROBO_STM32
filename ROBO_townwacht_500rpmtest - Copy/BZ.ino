
void setup_BUZZER() 
{
pinMode(PB5,OUTPUT);
pinMode(PC14,INPUT);
pinMode(PC13,OUTPUT);

}

void BZ(int tim) 
{  
  digitalWrite(PB5,HIGH); 
  delay(tim);
  digitalWrite(PB5,LOW); 
  delay(1); 
}



void LD(int tim) 
{  
  digitalWrite(PC13,LOW); 
  delay(tim);
  digitalWrite(PC13,HIGH); 
  delay(tim);  
}


void sw()
{
  
while(digitalRead(PC14)==HIGH){read_display_test();}
  BZ(100);
  digitalWrite(PC13,HIGH); 
  delay(500); 
}

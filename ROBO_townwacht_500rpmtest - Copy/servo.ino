#include <Servo.h>
Servo myservoB8; 
Servo myservoB9; 
Servo myservoB0; 
Servo myservoB1;
int SB0 = 0;
int SB1 = 0;
int pos = 0; 
void setup_servo() 
{
myservoB8.attach(PB8); 
myservoB9.attach(PB9); 
myservoB0.attach(PB0);
myservoB1.attach(PB1);
}

void S_down() 
{
  
              
    
            myservoB8.write(30); 
           
     
                
}


void servo_kang() 
{
   
     
            myservoB0.write(107); 
            myservoB1.write(85);            
            delay(100);
                
}

void servo_kangmark() 
{
   
            myservoB0.write(127); 
            myservoB1.write(65);            
            delay(100);
                
}

void S_UP() 
{
 
            myservoB8.write(115); 
            delay(300);
    
}



void servo_r()
{
     Motor(0,0,50);
       for(pos = 110; pos < 180; pos += 1) 
      {
            myservoB0.write(pos); 
            delay(1); 
       }
       for(pos = 90; pos < 160; pos += 1) 
      {
            myservoB1.write(pos); 
            delay(4); 
       }
       for(pos = 160; pos>=140; pos-=1)
      {
            myservoB1.write(pos); 
           delay(1); 
      } 
      Motor(0,0,10);
}

void servo_l()
{
     Motor(0,0,50);
       for(pos = 90; pos >= 10; pos -= 1) 
       
      {
            myservoB1.write(pos); 
            delay(1); 
       }
       for(pos = 77; pos>=20; pos-=1)
      {
            myservoB0.write(pos); 
           delay(5); 
      }
       for(pos = 30; pos < 50; pos += 1) 
      {
            myservoB0.write(pos); 
            delay(1); 
       }
       Motor(0,0,10);
}
void servo_big()
{
       Motor(0,0,20);
     
            myservoB0.write(72); 
            myservoB1.write(100);            
             delay(10);
       Motor(-5,-5,1);Motor(0,0,20);   
      
 }

 void servo_small()
{

       Motor(0,0,20);
     
            myservoB0.write(70); 
            myservoB1.write(120);            
             delay(10);
       Motor(-5,-5,1);Motor(0,0,20);   
  
           
}
void S_STS() 
{
    
      
            myservoB8.write(40);
            myservoB0.write(80); 
            myservoB1.write(100);
            Motor(0,0,100);
       
}

void S_HUB() 
{
   
         
            myservoB0.write(75); 
            myservoB1.write(125);
           delay(100);
            
          for(pos = 120; pos>=32; pos-=1)
      {
            myservoB8.write(pos); 
           delay(2); 
      } 
                
}

void left(){
   do{ read_sensor_F(); Motor(-c_l,c_l); } while(A0>200);Motor(-c_l,c_l,5);
                    do{ read_sensor_F(); Motor(-c_l,c_l);  } while(A2>200);            
                    Motor(50,-50,15);
                    Motor(0,0,2);  
  
}
void right(){
    do{ read_sensor_F(); Motor(c_r,-c_r); } while(A7>200); Motor(c_r,-c_r,5);
                      do{ read_sensor_F(); Motor(c_r,-c_r);  } while(A5>200);            
            
                      Motor(-50,50,15);
                      Motor(0,0,2);  
  
}

   
void TL()///////////////////////ใช้เลี้ยวซ้าย  
   {  
    Motor(20,20,30);Motor(0,0,50); 
    do{  Motor(-40,30); } while(digitalRead(PA10)==1);Motor(40,-20,5);Motor(0,0,1);
    do{  Motor(-10,30); } while(digitalRead(PA11)==1);
    do{  Motor(0,30); } while(digitalRead(PA11)==0);Motor(0,-20,10);Motor(0,0,1);
   
   
    while(1)
         {
             if(digitalRead(PA11)==0&&digitalRead(PA10)==0)
                { 
                  goto JP1;
                }
             else if (digitalRead(PA11)==0&&digitalRead(PA10)==1)
                {
                  Motor(-25,0);
                }
                   
             else
                {
                   Motor(0,-25);
                }
          }  
          JP1: {}  
          Motor(0,0,10);
          
   }

void TR()///////////////////////ใช้เลี้ยวขวา  
   {  
      Motor(20,20,30);Motor(0,0,50);   
      do{ Motor(30,-40); } while(digitalRead(PA11)==1);Motor(-30,40,5);Motor(0,0,1);
      do{  Motor(30,-10); } while(digitalRead(PA10)==1);
      do{ Motor(30,0); } while(digitalRead(PA10)==0);Motor(-20,0,10);Motor(0,0,1);
      
     
      
    while(1)
         {
             if(digitalRead(PA11)==0&&digitalRead(PA10)==0)
                { 
                  goto JP1;
                }
             else if (digitalRead(PA11)==0&&digitalRead(PA10)==1)
                {
                  Motor(-25,0);
                }
                   
             else
                {
                   Motor(0,-25);
                }
          }  
          JP1: {}  
          Motor(0,0,10);
    }



void UT_R() ///////////////////////////////////กลับหลังหันขวา
    {        
       Motor(40,-40,150);   
       do{ read_sensor_F(); Motor(40,-40); } while(A7>200);    
       do{ read_sensor_F(); Motor(40,-40); } while(A5>200); 
       Motor(-50,50,10); Motor(0,0,50);
             
   }
void UT_L() ///////////////////////////////////กลับหลังหันซ้าย
   {        
       Motor(-40,40,150);   
       do{ read_sensor_F(); Motor(-40,40); } while(A0>200);    
       do{ read_sensor_F(); Motor(-40,40); } while(A2>200); 
       Motor(50,-50,10); Motor(0,0,50);
             
   }

void Motor(int PL,int PR, int tm)   ////////////////////////////////// คำสั่งควบคุมมอเตอร์ เช่น  Motor(100,100,50);
   {
       int L = 0;
       int R = 0;
       L = (PL*255)/100;
       R = (PR*255)/100;
       
       do 
         {
            t++;
            Motor_begin(L,R);     
         }
       while (t<tm*200);    
       t=0; 
    }

void Motor(int PL,int PR)   ////////////////////////////////// คำสั่งควบคุมมอเตอร์ เช่น  Motor(100,100);
   {
      int L = 0;
      int R = 0;
      L = (PL*255)/100;
      R = (PR*255)/100;
      Motor_begin(L,R); 
   }


void Motor_begin(int sl,int sr)    
   {  
      if(sr>255)
      sr = 255;
      else if(sr<-255)
      sr = -255;
    
      if(sl>255)
      sl = 255;
      else if(sl<-255)
       sl = -255;
    
      if(sl>0)
        {
             digitalWrite(IN1L,HIGH);
             digitalWrite(IN2L,LOW);     
             analogWrite(PWML,sl);
         }
      else if(sl<0)
         {    
             digitalWrite(IN1L,LOW);
             digitalWrite(IN2L,HIGH);
             analogWrite(PWML,-sl);
         }
      else
         {        
             digitalWrite(IN1L,LOW);
             digitalWrite(IN2L,LOW);
             analogWrite(PWML,255);
         }  
  
      if(sr>0)
         {
             digitalWrite(IN1R,HIGH);
             digitalWrite(IN2R,LOW);
             analogWrite(PWMR,sr);
         }
      else if(sr<0)
         {    
            digitalWrite(IN1R,LOW);
            digitalWrite(IN2R,HIGH);
            analogWrite(PWMR,-sr);
          }
       else
          {        
             digitalWrite(IN1R,LOW);
             digitalWrite(IN2R,LOW);
              analogWrite(PWMR,255);
          }    
    }

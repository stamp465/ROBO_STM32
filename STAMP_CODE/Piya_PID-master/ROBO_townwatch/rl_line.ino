


void colorline (int PL ,int PR, int KP,  char CH_SENSOR, char LR, int RT) ///////// colorline (35 ,35, 10, 'l','l', 10);     กรอบสีอยู่ทางซ้าย  เลี้ยวซ้าย 
                                                                          //////////  colorline (35 ,35, 10, 'r','r', 10);    กรอบสีอยู่ทางขวา   เลี้ยวขวา
                                                                          //////////  colorline (35 ,35, 10, 'r','c', 10);    กรอบสีอยู่ทางขวา    ตรงไปไม่เลี้ยว
{
  int SPL = 0;
  int SPR = 0;
  SPL = (PL*255)/100;
  SPR = (PL*255)/100;

     if(CH_SENSOR=='r')  //// /*******************////  ถ้าพื้นสีอยู่ทางขวา  
        {
          read_sensor_F();
    
          while(1)
            {    
                read_sensor_values_R();
                P = error;
                I = I + previous_I;
                D = error - previous_error;    
                PID_value = (KP*P) + (0.0015*I) + (50*D);     
                previous_I=I;  
                previous_I=I;
                previous_error=error;
                Motor(SPL + PID_value,SPR - PID_value); 
              
              if 
                 ((A0<100)&&(A3<100)&&(A4<200)
                 ||(A0<100)&&(A2<100)
                 ||(A0<100)&&(A3<100)
                 ||(A0<100)&&(A4<100)
                 ||(A7<100)
                 
                 )
              break;
             }
                   Motor(0,0,2);
        }
      else
        {
          read_sensor_F();
    
          while(1)
            {    
                read_sensor_values_L();
                P = error;
                I = I + previous_I;
                D = error - previous_error;    
                PID_value = (KP*P) + (0.0015*I) + (50*D);     
                previous_I=I;  
                previous_I=I;
                previous_error=error;
                 Motor(SPL + PID_value,SPR - PID_value); 
              
              if 
                 ((A7<100)&&(A5<100)&&(A3<100)
                 ||(A7<100)&&(A5<100)
                 ||(A7<100)&&(A4<100)
                 ||(A7<100)&&(A3<100)
                 ||(A0<100)
                 )
              break;
             }

             Motor(0,0,2);
          
        }

     ///////////////////////////////////////////////////////////////////////////////   

    if (LR=='l')
       {
          do{ Motor(20,20); } while(PA3>900); Motor(20,20,50); Motor(-30,-30,10);Motor(0,0,5);  
           do{ read_sensor_F(); Motor(-20,20); } while(A0>200);
          do{ read_sensor_F(); Motor(-20,20); } while(A3>200);
          
            
              Motor(20,-20,RT);
              Motor(0,0,2);
       }
     else if  (LR=='r')
       {
           do{ Motor(20,20); } while(PA2>900); Motor(20,20,50); Motor(-30,-30,10);Motor(0,0,5); 
            do{ read_sensor_F(); Motor(20,-20); } while(A7>200); 
           do{ read_sensor_F(); Motor(20,-20); } while(A4>200);
          
            
               Motor(-20,20,RT);
               Motor(0,0,2);
        }
      else
        {
            
              while(1)
                  {
                     read_sensor_F();  
                      if ((A0>=100)&&(A7<100))
                        {
                           do{ Motor(SPL,SPR); } while(PA2>900);   delay(20);
                           
                           
                           goto JP5;  
                        }                      
                                            
                     else if ((A0<100)&&(A7>=100))
                        {
                           do{  Motor(SPL,SPR);} while(PA3>900);    delay(20);
                           
                          
                           goto JP6;
                        }         
                     else if ((A0<70)&&(A7<70))
                        {
                           do{  Motor(SPL,SPR); } while(PA3>900);  delay(20);
                           
                           
                           goto JP6;
                        } 
                   }
               JP5: {}
               JP6: {}
               JP7: {}      
             }
        
     /*
    if(CH_SENSOR=='r')
         {
            if(LR=='l')
                {
                  do  {Motor(20,20);}  while(digitalRead(PA10)==1); Motor(-50,-50,10);Motor(0,0,5);
                  do{ read_sensor_F(); Motor(-50,50); } while(A0>200);
                  do{ read_sensor_F(); Motor(-50,50);  } while(A1>200);
            
                   Motor(50,-50,RT);
                   Motor(0,0,2);
                }
             else if  (LR=='r')
               {
                  do  {Motor(20,20);}  while(digitalRead(PA11)==1); Motor(-50,-50,10);Motor(0,0,5);
                  do{ read_sensor_F(); Motor(50,-50); } while(A7>200);
                  do{ read_sensor_F(); Motor(50,-50);  } while(A6>200);
            
                   Motor(-50,50,RT);
                   Motor(0,0,2);
                }
            else 
               {
                  do  {Motor(20,20);}  while(digitalRead(PA10)==1); Motor(-50,-50,RT);Motor(0,0,5);
                 
               }
            
            
         }
    else
         {
            if(LR=='l')
                {
                  do  {Motor(20,20);}  while(digitalRead(PA10)==1); Motor(-50,-50,10);Motor(0,0,5);
                  do{ read_sensor_F(); Motor(-50,50); } while(A0>200);
                  do{ read_sensor_F(); Motor(-50,50);  } while(A1>200);
            
                   Motor(50,-50,RT);
                   Motor(0,0,2);
                }
             else if  (LR=='r')
               {
                  do  {Motor(20,20);}  while(digitalRead(PA11)==1); Motor(-50,-50,10);Motor(0,0,5);
                  do{ read_sensor_F(); Motor(50,-50); } while(A7>200);
                  do{ read_sensor_F(); Motor(50,-50);  } while(A6>200);
            
                   Motor(-50,50,RT);
                   Motor(0,0,2);
                }
            else 
               {
                  do  {Motor(20,20);}  while(digitalRead(PA11)==1); Motor(-50,-50,RT);Motor(0,0,5);
                 
               }
          
         }
    
     
*/




  
}




///      fline (30 ,30, 2, 10, 't',5 );     เข้าเส้นปรับเซนเซอร์หน้า ให้หุ่นตรง ใช้ในกรณีเดินแบบไม่มีเส้น
///      fline (30 ,30, 2, 10, 'f',5 );
///      fline (30 ,30, 2, 10, 'c',5 );

void fline (int SPL ,int SPR, int KP, int TIM, char CH_SENSOR, int RT)     /////////////////////////////เดินหน้าแบบตั่งค่า  ความเร็ว  KP  KI  KD และเวลาเอง
{  

  
    if (TIM>=12) 
       { 
        
          read_sensor_values_F(); 
           for(SP_BEGIN = 0  ; SP_BEGIN  < SPL; SP_BEGIN  += 5) 
               {
                  read_sensor_values_F();            
                  P = error;
                  I = I + previous_I;
                  D = error - previous_error;    
                  PID_value = (4*P) + (0.0015*I) + (60*D);    
                  previous_I=I;
                  previous_error=error;
              
                  Motor(SP_BEGIN + PID_value,  SP_BEGIN - PID_value); 
                  delay(TIM/5);    ///////////////////////////////////////ค่ามากจะออกตัวช้า
            
               }
         }
     else{}

     
  /////////////////////////////////////////////////////////////////////////
     if (TIM>=12)   ///////////////ถ้าเวลา มากกว่า 12
        {
           read_sensor_values_F(); 
           do
              {
                  T++;

                  read_sensor_values_F();
            
                  P = error;
                  I = I + previous_I;
                  D = error - previous_error;    
                  PID_value = (KP*P) + (0.0015*I) + (60*D);     
                  previous_I=I;
                  previous_error=error;
              
                  Motor(SPL + PID_value,SPR - PID_value); 
               }
            while (T<(TIM));
            T=0;

            read_sensor_values_F(); 
            for(SP_BEGIN = SPL  ; SP_BEGIN  >= 35; SP_BEGIN  -= 5) 
               {
                  read_sensor_values_F();            
                  P = error;
                  I = I + previous_I;
                  D = error - previous_error;    
                  PID_value = (6*P) + (0.0015*I) + (60*D);    
                  previous_I=I;
                  previous_error=error;
              
                  Motor(SP_BEGIN + PID_value,  SP_BEGIN - PID_value); 
                  delay(TIM/9.5);    ///////////////////////////////////////ค่ามากจะออกตัวช้า
            
               }

       
            read_sensor_F();
    
            while(1)
               {    
                   read_sensor_values_F();
                   P = error;
                   I = I + previous_I;
                   D = error - previous_error;    
                   PID_value = (5*P) + (0.0015*I) + ((KP*5)*D);     
                   previous_I=I;  
                   previous_I=I;
                   previous_error=error;
                   Motor(40 + PID_value,40 - PID_value); 
              if 
                  ((A0<200)&&(A3<200)&&(A4<200)&&(A7<200)
                  ||(A0<200)&&(A2<200)
                  ||(A0<200)&&(A3<200)
                  ||(A0<200)&&(A4<200)
                  ||(A7<200)&&(A4<200)
                  ||(A7<200)&&(A5<200)
                  ||(A7<200)&&(A3<200)
                  //||analogRead(PA1)>=2800
                  )
                  break;
               }
               Motor(-50,-50,2);
               Motor(0,0,1);
       }
   
  else   ///////////////ถ้าเวลาไม่ใช่มากกว่า 12
       {             
         read_sensor_F();
    
             while(1)
                   {    
                       read_sensor_values_F();
                       P = error;
                       I = I + previous_I;
                       D = error - previous_error;    
                       PID_value = (KP*P) + (0.0015*I) + (60*D);     
                       previous_I=I;  
                       previous_I=I;
                       previous_error=error;
                       Motor(SPL + PID_value,SPR - PID_value); 
                if 
                     ((A0<200)&&(A3<200)&&(A4<200)&&(A7<200)
                     ||(A0<200)&&(A2<200)
                     ||(A0<200)&&(A3<200)
                     ||(A0<200)&&(A4<200)
                     ||(A7<200)&&(A4<200)
                     ||(A7<200)&&(A5<200)
                      ||(A7<200)&&(A3<200)
       
                     )
                break;
                   }
             }

       
///////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////  
  
   
      if(CH_SENSOR=='f') /////////////////////
         {  
            while(1)
               {
                   read_sensor_F();   
                   if ((A0>=200)&&(A7<200))
                      {
                             
                         Motor(-50,-50,RT);Motor(0,0,1);
                                
                               goto JP2;                          
                       }
                    else if ((A0<200)&&(A7>=200))
                       {
                             
                       
                            Motor(-50,-50,RT);Motor(0,0,1); 
                                goto JP3;              
                        }       
                                     
                     else if ((A0<200)&&(A7<200))     
                        {
                            
                       
                           Motor(-50,-50,RT);Motor(0,0,1); 
                                 goto JP4;
                        }
                            
                }
               JP2: {}
               JP3: {}
               JP4: {}
           }
       else if (CH_SENSOR=='g')
           {
               while(1)
                  {
                     read_sensor_F();  
                      if ((A0>=200)&&(A7<200))
                        {
                           do  {Motor(SPL,SPR);}  while(digitalRead(PA11)==1); 
                           
                           goto JP5;  
                        }                      
                                            
                     else if ((A0<200)&&(A7>=200))
                        {
                           do  {Motor(SPL,SPR);}  while(digitalRead(PA10)==1);  
                            
                           goto JP6;
                        }         
                     else if ((A0<200)&&(A7<200))
                        {
                           do  {Motor(SPL,SPR);}  while(digitalRead(PA10)==1);  
                           
                           goto JP6;
                        } 
                   }
               JP5: {}
               JP6: {}
               JP7: {}
           }
        
       else /////////////////////
           {  
              while(1)
                  {
                     read_sensor_F();  
                      if ((A0>=200)&&(A7<200))
                        {
                           do  {Motor(20,20);}  while(digitalRead(PA11)==1); 
                           Motor(-50,-50,RT);
                           Motor(0,0,1); 
                           goto JP5;  
                        }                      
                                            
                     else if ((A0<200)&&(A7>=200))
                        {
                           do  {Motor(20,20);}  while(digitalRead(PA10)==1);  
                           Motor(-50,-50,RT);
                           Motor(0,0,1); 
                           goto JP6;
                        }         
                     else if ((A0<200)&&(A7<200))
                        {
                           do  {Motor(20,20);}  while(digitalRead(PA10)==1);  
                           Motor(-50,-50,RT);
                           Motor(0,0,1); 
                           goto JP6;
                        } 
                   }
               JP8: {}
               JP9: {}
               JP10: {}      
             }
}

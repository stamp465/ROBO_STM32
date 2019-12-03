

void fline (int SPL ,int SPR, int KP, int TIM, char CH_SENSOR, char LR, int RT)     /////////////////////////////เดินหน้าแบบตั่งค่า  ความเร็ว  KP  KI  KD และเวลาเอง
    {  
      
  
       if (TIM>=12) 
       { 
        
          read_sensor_values_F(); 
           for(SP_BEGIN = 0  ; SP_BEGIN  < SPL; SP_BEGIN  += 2) 
               {
                  read_sensor_values_F();            
                  P = error;
                  I = I + previous_I;
                  D = error - previous_error;    
                  PID_value = (2*P) + (0.0015*I) + (60*D);    
                  previous_I=I;
                  previous_error=error;
              
                  Motor(SP_BEGIN + PID_value,  SP_BEGIN - PID_value); 
                  delay(5);    ///////////////////////////////////////ค่ามากจะออกตัวช้า
            
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
                  PID_value = (KP*P) + (0.0015*I) + (30*D);     
                  previous_I=I;
                  previous_error=error;
              
                  Motor(SPL + PID_value,SPR - PID_value); 
               }
            while (T<(TIM*5));
            T=0;

            read_sensor_values_F(); 
            for(SP_BEGIN = SPL  ; SP_BEGIN  >= 30; SP_BEGIN  -= 2) 
               {
                  read_sensor_values_F();            
                  P = error;
                  I = I + previous_I;
                  D = error - previous_error;    
                  PID_value = (3*P) + (0.0015*I) + (20*D);    
                  previous_I=I;
                  previous_error=error;
              
                  Motor(SP_BEGIN + PID_value,  SP_BEGIN - PID_value); 
                  delay(5);    ///////////////////////////////////////ค่ามากจะออกตัวช้า
            
               }

       
            read_sensor_F();
    
            while(1)
               {    
                   read_sensor_values_F();
                   P = error;
                   I = I + previous_I;
                   D = error - previous_error;    
                   PID_value = (4*P) + (0.0015*I) + (20*D);     
                   previous_I=I;  
                   previous_I=I;
                   previous_error=error;
                   Motor(30 + PID_value,30 - PID_value); 
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


//////////////////////////////////////////////////////////////////////////////////////////////    

      if(CH_SENSOR=='f') /////////////////////
         {  
            while(1)
               {
                   read_sensor_F();   
                   if ((A6<200)||(A7<200))
                      {
                         Motor(20,20);  while(analogRead(PA2)>1000){} Motor(20,20,10); 
                         Motor(20,20);  while(analogRead(PA2)<1000){}      
                         Motor(-30,-30,2);Motor(0,0,1);
                                
                               goto JP2;                          
                       }
                    else if ((A0<200)||(A0<200))
                       {
                            Motor(20,20);  while(analogRead(PA3)>1000){} Motor(20,20,10);
                            Motor(20,20);  while(analogRead(PA3)<1000){} 
                       
                            Motor(-30,-30,2);Motor(0,0,1); 
                                goto JP3;              
                        }       
                                     
                     else if ((A0<200)&&(A7<200))     
                        {
                           Motor(20,20);  while(analogRead(PA3)>1000){} Motor(20,20,10);
                            Motor(20,20);  while(analogRead(PA3)<1000){} 
                       
                           Motor(-30,-30,2);Motor(0,0,1); 
                                 goto JP4;
                        }
                            
                }
               JP2: {}
               JP3: {}
               JP4: {}
           }
        
       else /////////////////////
           {  
              while(1)
                  {
                     read_sensor_F();  
                      if ((A6<200)||(A7<200))
                        {
                           do  {Motor(20,20);}  while(digitalRead(PA11)==1); 
                           Motor(-40,-40,10);
                           Motor(0,0,2); 
                           goto JP5;  
                        }                      
                                            
                     else if ((A0<200)||(A0<200))
                        {
                           do  {Motor(20,20);}  while(digitalRead(PA10)==1);  
                           Motor(-40,-40,10);
                           Motor(0,0,2); 
                           goto JP6;
                        }         
                     else if ((A0<200)&&(A7<200))
                        {
                           do  {Motor(20,20);}  while(digitalRead(PA10)==1);  
                           Motor(-40,-40,10);
                           Motor(0,0,2); 
                           goto JP6;
                        } 
                   }
               JP5: {}
               JP6: {}
               JP7: {}      
             }
///////////////////////////////////////////////////////////////////////////////////////////////////////
  if (TIM>=12)
     {
       if(LR=='l') /////////////////////  ถ้าส่งค่า l เลี้ยวซ้าย  ค่า r เลี้ยวขวา
          { 
            
             if (CH_SENSOR=='f')   ////  ถ้าส่งค่า f เซ็นเซอร์หน้า  ค่า c  เซ็นเซอรกลาง
                {
                    Motor(20,20,10);
                    do{ read_sensor_F(); Motor(-(f_l/3),f_l); } while(A0>200);Motor(-(f_l/3),f_l,5); 
                   
                    do{ read_sensor_F(); Motor(-(f_l/3),f_l);  } while(A0<200);
                    do{ read_sensor_F(); Motor(-(f_l/3),f_l);  } while(A1<200);
                    Motor(20,-70,RT);
                    Motor(0,0,2);
                 }
              else
                 {  
                    do{ read_sensor_F(); Motor(-c_l,c_l); } while(A0>200);Motor(-c_l,c_l,5);
                    do{ read_sensor_F(); Motor(-c_l,c_l); } while(A0<200);
                    do{ read_sensor_F(); Motor(-c_l,c_l);  } while(A2>200);            
                    Motor(50,-50,RT);
                    Motor(0,0,2);
                 }
            }
        
        else /////////////////////เช็คเซนเซอร์หน้า กับ กลาง    กำหนด 1 กับ  2
            {  
               
               if (CH_SENSOR=='f')   ////  ถ้าส่งค่า 1 เซ็นเซอร์หน้า  ค่า 0  เซ็นเซอร์หลัง
                  {
                     Motor(20,20,10);
                     do{ read_sensor_F(); Motor(c_r,-(c_r/3)); } while(A7>200); Motor(c_r,-(c_r/3),5);
                     
                      do{ read_sensor_F(); Motor(c_r,-(c_r/3)); } while(A7<200);
                      do{ read_sensor_F(); Motor(c_r,-(c_r/3)); } while(A6<200);
                     Motor(-70,20,RT);
                     Motor(0,0,2);
                   }
               else
                   {  
                      do{ read_sensor_F(); Motor(c_r,-c_r); } while(A7>200); Motor(c_r,-c_r,5);
                      do{ read_sensor_F(); Motor(c_r,-c_r); } while(A7<200);
                      do{ read_sensor_F(); Motor(c_r,-c_r);  } while(A5>200);            
            
                      Motor(-50,50,RT);
                      Motor(0,0,2);
                   }
             }
     }
  else 
     {
       if(LR=='l') /////////////////////  ถ้าส่งค่า l เลี้ยวซ้าย  ค่า r เลี้ยวขวา
          { 
             if (CH_SENSOR=='f')   ////  ถ้าส่งค่า f เซ็นเซอร์หน้า  ค่า c  เซ็นเซอรกลาง
                {
                    Motor(-40,-40,5);
                    do{ read_sensor_F(); Motor(-(f_l/3),f_l); } while(A0>200); Motor(-(f_l/3),f_l,5); 
                    
                    do{ read_sensor_F(); Motor(-(f_l/3),f_l);  } while(A0<200);
                    do{ read_sensor_F(); Motor(-(f_l/3),f_l);  } while(A1<200);
                    Motor(20,-70,RT);
                    Motor(0,0,2);
                 }
              else
                 {  
                    Motor(-40,-40,5);
                    do{ read_sensor_F(); Motor(-c_l,c_l); } while(A0>200); Motor(-c_l,c_l,5);
                    do{ read_sensor_F(); Motor(-c_l,c_l); } while(A0<200); 
                    do{ read_sensor_F(); Motor(-c_l,c_l); } while(A2>200);            
                    Motor(50,-50,RT);
                    Motor(0,0,2);
                 }
            }
        
        else /////////////////////เช็คเซนเซอร์หน้า กับ กลาง    กำหนด 1 กับ  2
            {  
               if (CH_SENSOR=='f')   ////  ถ้าส่งค่า 1 เซ็นเซอร์หน้า  ค่า 0  เซ็นเซอร์หลัง
                  {
                     Motor(-40,-40,5);
                     do{ read_sensor_F(); Motor(c_r,-(c_r/3)); } while(A7>200); Motor(c_r,-(c_r/3),5);
                   
                     do{ read_sensor_F(); Motor(c_r,-(c_r/3));  } while(A7<200);
                     do{ read_sensor_F(); Motor(c_r,-(c_r/3));  } while(A6<200);
                     Motor(-70,20,RT);
                     Motor(0,0,2);
                   }
               else
                   {  
                      Motor(-40,-40,5);
                      do{ read_sensor_F();Motor(c_r,-c_r); } while(A7>200);Motor(c_r,-c_r,5);
                      do{ read_sensor_F();Motor(c_r,-c_r); } while(A7<200);
                      do{ read_sensor_F();Motor(c_r,-c_r);  } while(A5>200);            
            
                      Motor(-50,50,RT);
                      Motor(0,0,2);
                   }
             }
     }
}



void bline (int SPL ,int SPR, int KP, int TIM, char CH_SENSOR, char LR, int RT)     /////////////////////////////เดินหน้าแบบตั่งค่า  ความเร็ว  KP  KI  KD และเวลาเอง
{  
 
  
    if (TIM>=12) 
   { 
        
     read_sensor_values_B(); 
     for(SP_BEGIN = 0  ; SP_BEGIN  < SPL; SP_BEGIN  += 5) 
      {
              read_sensor_values_B();            
              P = error;
              I = I + previous_I;
              D = error - previous_error;    
              PID_value = (4*P) + (0.0015*I) + (60*D);    
              previous_I=I;
              previous_error=error;
              
            Motor(-(SP_BEGIN - PID_value),-(SP_BEGIN + PID_value)); 
            delay(TIM/5);    ///////////////////////////////////////ค่ามากจะออกตัวช้า
            
       }
   }
   else{}

     
  /////////////////////////////////////////////////////////////////////////
 if (TIM>=12)
  {
  read_sensor_values_B(); 
  do
  {
    T++;

             read_sensor_values_B();
            
              P = error;
              I = I + previous_I;
              D = error - previous_error;    
              PID_value = (KP*P) + (0.0015*I) + (60*D);     
              previous_I=I;
              previous_error=error;
              Motor(-(SPL - PID_value),-(SPR+ PID_value)); 
    }
    while (T<(TIM*15));
    T=0; 
      
     read_sensor_values_B(); 
     for(SP_BEGIN = SPL  ; SP_BEGIN  >= 25; SP_BEGIN  -= 5)  
      {
              read_sensor_values_B();            
              P = error;
              I = I + previous_I;
              D = error - previous_error;    
              PID_value = (3*P) + (0.0015*I) + (60*D);    
              previous_I=I;
              previous_error=error;
              
            Motor(-(SP_BEGIN - PID_value),-(SP_BEGIN + PID_value)); 
            delay(TIM/6);    ///////////////////////////////////////ค่ามากจะออกตัวช้า
            
       }

       
    read_sensor_B();
    
    while(1)
        {    
            read_sensor_values_B();
              P = error;
              I = I + previous_I;
              D = error - previous_error;    
              PID_value = (2*P) + (0.0015*I) + ((KP*5)*D);     
              previous_I=I;  
              previous_I=I;
              previous_error=error;
            Motor(-(25 - PID_value),-(25 + PID_value)); 
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
  Motor(20,20,2);
  Motor(0,0,1);
  }
   
  else
  {
       read_sensor_B();
    
    while(1)
        {    
            read_sensor_values_B();
              P = error;
              I = I + previous_I;
              D = error - previous_error;    
              PID_value = (KP*P) + (0.0015*I) + ((KP*5)*D);     
              previous_I=I;  
              previous_I=I;
              previous_error=error;
            Motor(-(SPL - PID_value),-(SPR+ PID_value)); 
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
////////////////////////////////*******************************///////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////    

  if(CH_SENSOR=='f') /////////////////////เช็คเซนเซอร์หน้า กับ กลาง    กำหนด 1 กับ  2
     {  
     while(1)
       {
         read_sensor_B();   
         if ((A0>=200)&&(A7<200))
             {
                do{ read_sensor_B(); Motor(-20,-20); } while(A7<200);   
                 delay(20);
                 Motor(50,50,5);Motor(0,0,1); 
                       goto JP2;  
             }          
          else if ((A0<200)&&(A7>=200))     
             {  
               do{ read_sensor_B(); Motor(-20,-20); } while(A0<200);   
                      
                       delay(20);
                       Motor(50,50,5);Motor(0,0,1);  
                       goto JP3;   
             }
                      
          else 
             {
                do{ read_sensor_B(); Motor(-30,-30); } while(A7<200);    
                delay(20);        
                Motor(50,50,5);Motor(0,0,1);       
                       goto JP4;
             } 
        }    
                       
       JP2: {}
       JP3: {}
       JP4: {}
     }             
       
 else /////////////////////เช็คเซนเซอร์หน้า กับ กลาง    กำหนด 1 กับ  2
     {  
     while(1)
       {
         read_sensor_B();  
         if ((A0>=200)&&(A7<200))
            {
               do  {Motor(-20,-20);}  while(digitalRead(PA10)==1); Motor(30,30,5);Motor(0,0,5); goto JP5;  
            }   
                  
         else if ((A0<200)&&(A7>=200))  
            {            
               do  {Motor(-20,-20);} while(digitalRead(PA11)==1);  Motor(30,30,5);Motor(0,0,5); goto JP6;
            }         
         else 
            {
                  do  {Motor(-20,-20);} while(digitalRead(PA11)==1);  Motor(30,30,5);Motor(0,0,5); goto JP7;
            }
         
      }
     JP5: {}
     JP6: {}
     JP7: {}
      
       }
///////////////////////////////////////////////////////////////////////////////////////////////////////

    if(LR=='l') /////////////////////  ถ้าส่งค่า l เลี้ยวซ้าย  ค่า r เลี้ยวขวา
       { 
        if (CH_SENSOR=='f')   ////  ถ้าส่งค่า f เซ็นเซอร์หน้า  ค่า c  เซ็นเซอรกลาง
          {
             do{ read_sensor_B(); Motor(-70,20); } while(A0>200);Motor(-70,20,10); 
             do{ read_sensor_B(); Motor(-70,20);  } while(A3>200);
             Motor(70,-30,RT);
             Motor(0,0,2);
          }
        else
          {  
                        
             do{ read_sensor_F(); Motor(-bc_l,bc_l); } while(A0>200); Motor(-bc_l,bc_l,10); 
             do{ read_sensor_F(); Motor(-bc_l,bc_l); } while(A2>200);
            
             Motor(60,-60,RT);
             Motor(0,0,2);
          }
       }
        
    else /////////////////////เช็คเซนเซอร์หน้า กับ กลาง    กำหนด 1 กับ  2
       {  
         if (CH_SENSOR=='f')   ////  ถ้าส่งค่า 1 เซ็นเซอร์หน้า  ค่า 0  เซ็นเซอร์หลัง
          {
             do{ read_sensor_B(); Motor(20,-70); } while(A7>200); Motor(20,-70,10);
             do{ read_sensor_B(); Motor(20,-70);  } while(A4>200);
             Motor(-30,70,RT);
             Motor(0,0,2);
          }
        else
          {  
             do{ read_sensor_F(); Motor(bc_r,-bc_r); } while(A7>200); Motor(bc_r,-bc_r,10);
             do{ read_sensor_F(); Motor(bc_r,-bc_r); } while(A5>200);
            
             Motor(-60,60,RT);
             Motor(0,0,2);
          }
       }
     
}

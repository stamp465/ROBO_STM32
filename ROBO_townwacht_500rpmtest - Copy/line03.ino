



void fline (int SPL ,int SPR, int KP, int TIM,int RT)     /////////////////////////////เดินหน้าแบบตั่งค่า  ความเร็ว  KP  KI  KD และเวลาเอง
{  
   
  
  read_sensor_values_F(); 
  do
  {
    T++;

             read_sensor_values_F();
            
              P = error;
              I = I + previous_I;
              D = error - previous_error;    
              PID_value = (KP*P) + (0.0015*I) + ((KP*5)*D);     
              previous_I=I;
              previous_error=error;

              
              
            Motor(SPL + PID_value,SPR - PID_value); 
    }
    while (T<(TIM*15));
    T=0;

 
  Motor(-50,-50,RT); Motor(0,0,1);
}
       





void ch_color_floor_spi_r() 
{    
   
    read_sensor_F();
    if ((A5 < 176)&&(A6 < 203) && (A7 > 250)  )         ///////////////////ถ้าเครื่องหมาย < ให้ บวกค่าที่อ่านได้อีก 30 
        {                                                   ///////////////////ถ้าเครื่องหมาย > ให้ ลบค่าที่อ่านได้อีก 30 
            color_spi_r = 1;
            color_spi_tr = "RED";
        }

    else if ( (A5 > 3)&&(A6 < 170) && (A7 < 180) )
        {
            color_spi_r = 2;
            color_spi_tr = "GREEN";
        }
        
    else if ((A5 < 105)&& (A6 >125) && (A7 < 75) ) 
        {
            color_spi_r = 3;
            color_spi_tr = "BLUE";
        }
        
     else if ((A5 < 400)&&(A6 < 2500) && (A7 > 400.)  )  
        {
            color_spi_r = 4;
            color_spi_tr = "YELLOW";
        }
        
    else if ((A5 < 80) &&(A6 < 100) &&(A7 < 85)  ) 
        {
            color_spi_r = 5;
            color_spi_tr= "Blak";
        }
        
     else if ((A5 > 360) &&(A6 > 370) && (A7 < 460) ) 
        {
            color_spi_r = 6;
            color_spi_tr = "WITH";
        }
   
    else 
        {
            color_spi_r = 7;
            color_spi_tr = "NONE";      
        }   
 
}


void spi_color_r_a ()
    {
        ch_color_floor_spi_r(); 
      
        if (color_spi_r == 1)
            {
               color_a = 1.0;
            }
            
        else if (color_spi_r == 2)
            {
               color_a = 2.0;
            }
            
        else if (color_spi_r == 3)
            {
               color_a = 3.0;
            }
            
         else if (color_spi_r == 4)
            {
               color_a = 4.0;
            }
         else if (color_spi_r == 5)
            {
               color_a = 5.0;
            }
            
        else
            {
              color_a = 6.0;
            }

        BZ(30) ; delay(100); BZ(30) ;
      
    }

void spi_color_r_b ()
    {
        ch_color_floor_spi_r() ;
      
        if (color_spi_r == 1)
            {
               color_b = 1.0;
            }
            
        else if (color_spi_r == 2)
            {
               color_b = 2.0;
            }
            
        else if (color_spi_r == 3)
            {
               color_b = 3.0;
            }
            
         else if (color_spi_r == 4)
            {
               color_b = 4.0;
            }
         else if (color_spi_r == 5)
            {
               color_b = 5.0;
            }
            
        else
            {
              color_b = 6.0;
            }

        BZ(30) ; delay(100); BZ(30) ;
      
    }

void spi_color_r_c ()
    {
        ch_color_floor_spi_r(); 
      
        if (color_spi_r == 1)
            {
               color_c = 1.0;
            }
            
        else if (color_spi_r == 2)
            {
               color_c = 2.0;
            }
            
        else if (color_spi_r == 3)
            {
               color_c = 3.0;
            }
            
         else if (color_spi_r == 4)
            {
               color_c = 4.0;
            }
         else if (color_spi_r == 5)
            {
               color_c = 5.0;
            }
            
        else
            {
              color_c = 6.0;
            }

        BZ(30) ; delay(100); BZ(30) ;
      
    }

 
void spi_color_r_d ()
    {
        ch_color_floor_spi_r(); 
      
        if (color_spi_r == 1)
            {
               color_d = 1.0;
            }
            
        else if (color_spi_r == 2)
            {
               color_d = 2.0;
            }
            
        else if (color_spi_r == 3)
            {
               color_d = 3.0;
            }
            
         else if (color_spi_r == 4)
            {
               color_d = 4.0;
            }
         else if (color_spi_r == 5)
            {
               color_d = 5.0;
            }
            
        else
            {
              color_d = 6.0;
            }

        BZ(30) ; delay(100); BZ(30) ;
      
    }

 
void spi_color_r_e ()
    {
        ch_color_floor_spi_r(); 
      
        if (color_spi_r == 1)
            {
               color_e = 1.0;
            }
            
        else if (color_spi_r == 2)
            {
               color_e = 2.0;
            }
            
        else if (color_spi_r == 3)
            {
               color_e = 3.0;
            }
            
         else if (color_spi_r == 4)
            {
               color_e = 4.0;
            }
         else if (color_spi_r == 5)
            {
               color_e = 5.0;
            }
            
        else
            {
              color_e = 6.0;
            }

        BZ(30) ; delay(100); BZ(30) ;
      
    }

    



void ch_color_floor_spi_l() 
{    
   
   
    read_sensor_F();
    if ((A0 > 220)&&(A1 < 196) && (A2 < 186)  )         ///////////////////ถ้าเครื่องหมาย < ให้ บวกค่าที่อ่านได้อีก 30 
       {                                                   ///////////////////ถ้าเครื่องหมาย > ให้ ลบค่าที่อ่านได้อีก 30 
          color_spi_l = 1;
          color_spi_tl = "RED";
       }

    else if ((A0 < 171)&&(A1 < 163) && (A2 > 24)  )
       {
          color_spi_l = 2;
          color_spi_tl = "GREEN";
       }
       
    else if ((A0 < 70)&& (A1 >110) && (A2 < 120) ) 
       {
          color_spi_l = 3;
          color_spi_tl = "BLUE";
       }
       
    else if ((A0 < 571)&&(A1 < 250) && (A2 > 250)  ) 
       {
          color_spi_l = 4;
          color_spi_tl = "YELLOW";
       }
       
    else if ((A0 < 75)&&(A1 < 90) && (A2 < 60)  ) 
       {
          color_spi_l= 5;
          color_spi_tl= "Blak";
       }
       
     else if ((A0 < 460)&&(A1 > 370) && (A2 > 400)  ) 
       {
          color_spi_l = 6;
          color_spi_tl = "WITH";
       }
   
    else 
       {
          color_spi_l = 7;
          color_spi_tl = "NONE";      
       }   
 
}


void spi_color_l_a ()
    {
        ch_color_floor_spi_l(); 
      
        if (color_spi_l == 1)
            {
               color_a = 1.0;
            }
            
        else if (color_spi_l == 2)
            {
               color_a = 2.0;
            }
            
        else if (color_spi_l == 3)
            {
               color_a = 3.0;
            }
            
         else if (color_spi_l == 4)
            {
               color_a = 4.0;
            }
         else if (color_spi_l == 5)
            {
               color_a = 5.0;
            }
            
        else
            {
              color_a = 6.0;
            }

        BZ(30) ; delay(100); BZ(30) ;
      
    }

void spi_color_l_b ()
    {
        ch_color_floor_spi_l() ;
      
        if (color_spi_l == 1)
            {
               color_b = 1.0;
            }
            
        else if (color_spi_l == 2)
            {
               color_b = 2.0;
            }
            
        else if (color_spi_l == 3)
            {
               color_b = 3.0;
            }
            
         else if (color_spi_l == 4)
            {
               color_b = 4.0;
            }
         else if (color_spi_l == 5)
            {
               color_b = 5.0;
            }
            
        else
            {
              color_b = 6.0;
            }

        BZ(30) ; delay(100); BZ(30) ;
      
    }

void spi_color_l_c ()
    {
        ch_color_floor_spi_l(); 
      
        if (color_spi_l == 1)
            {
               color_c = 1.0;
            }
            
        else if (color_spi_l == 2)
            {
               color_c = 2.0;
            }
            
        else if (color_spi_l == 3)
            {
               color_c = 3.0;
            }
            
         else if (color_spi_l == 4)
            {
               color_c = 4.0;
            }
         else if (color_spi_l == 5)
            {
               color_c = 5.0;
            }
            
        else
            {
              color_c = 6.0;
            }

        BZ(30) ; delay(100); BZ(30) ;
      
    }

 
void spi_color_l_d ()
    {
        ch_color_floor_spi_l(); 
      
        if (color_spi_l == 1)
            {
               color_d = 1.0;
            }
            
        else if (color_spi_l == 2)
            {
               color_d = 2.0;
            }
            
        else if (color_spi_l == 3)
            {
               color_d = 3.0;
            }
            
         else if (color_spi_l == 4)
            {
               color_d = 4.0;
            }
         else if (color_spi_l == 5)
            {
               color_d = 5.0;
            }
            
        else
            {
              color_d = 6.0;
            }

        BZ(30) ; delay(100); BZ(30) ;
      
    }

 
void spi_color_l_e ()
    {
        ch_color_floor_spi_l(); 
      
        if (color_spi_l == 1)
            {
               color_e = 1.0;
            }
            
        else if (color_spi_l == 2)
            {
               color_e = 2.0;
            }
            
        else if (color_spi_l == 3)
            {
               color_e = 3.0;
            }
            
         else if (color_spi_l == 4)
            {
               color_e = 4.0;
            }
         else if (color_spi_l == 5)
            {
               color_e = 5.0;
            }
            
        else
            {
              color_e = 6.0;
            }

        BZ(30) ; delay(100); BZ(30) ;
      
    }

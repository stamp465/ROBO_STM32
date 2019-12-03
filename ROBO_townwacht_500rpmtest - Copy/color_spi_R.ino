



void ch_color_floor_spi_r() 
{    
   
    read_sensor_F();
    if ((A5 < 150)&&(A6 < 220) && (A7 > 140)  )         ///////////////////ถ้าเครื่องหมาย < ให้ บวกค่าที่อ่านได้อีก 100 
        {                                                   ///////////////////ถ้าเครื่องหมาย > ให้ ลบค่าที่อ่านได้อีก 100 
            color_spi_r = 1;
            color_spi_tr = "RED";
        }

    else if ( (A5 > 120)&&(A6 < 290) && (A7 < 175) )
        {
            color_spi_r = 2;
            color_spi_tr = "GREEN";
        }
        
    else if ((A5 < 240)&& (A6 >230) && (A7 < 160) ) 
        {
            color_spi_r = 3;
            color_spi_tr = "BLUE";
        }
        
     else if ((A5 < 560)&&(A6 < 480) && (A7 > 435)  )  
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

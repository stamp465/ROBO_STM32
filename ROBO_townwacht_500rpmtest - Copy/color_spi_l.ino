



void ch_color_floor_spi_l() 
{    
   
   
    read_sensor_F();
    if ((A0 > 250)&&(A1 < 220) && (A2 < 130)  )         ///////////////////ถ้าเครื่องหมาย < ให้ บวกค่าที่อ่านได้อีก 100 
       {                                                   ///////////////////ถ้าเครื่องหมาย > ให้ ลบค่าที่อ่านได้อีก 100 
          color_spi_l = 1;
          color_spi_tl = "RED";
       }

    else if ((A0 < 170)&&(A1 < 180) && (A2 > 150)  )
       {
          color_spi_l = 2;
          color_spi_tl = "GREEN";
       }
       
    else if ((A0 < 160)&& (A1 >210) && (A2 < 270) ) 
       {
          color_spi_l = 3;
          color_spi_tl = "BLUE";
       }
       
    else if ((A0 < 490)&&(A1 < 180) && (A2 > 265)  ) 
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

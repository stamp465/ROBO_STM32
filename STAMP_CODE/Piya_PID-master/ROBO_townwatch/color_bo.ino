

void setup_TCS34725() 
{ 
    Serial.begin(9600);
    Serial.println("Makerblog.at - MuMs Color Sensor");
  if (tcs.begin()) 
    {
        Serial.println("Sensor gefunden");
    } 
  else 
    {
        Serial.println("TCS34725 nicht gefunden ... Ablauf gestoppt!");
        while (1);  
    }  
}
 
void ch_color_box() 
{ 
    uint16_t clearcol, red, green, blue;
    float average, r, g, b;
    delay(10); 
    tcs.getRawData(&red, &green, &blue, &clearcol);
 
    average = (red+green+blue)/3;
    r = red/average;
    g = green/average;
    b = blue/average;
 
      Serial.print("\tClear:"); Serial.print(clearcol);
      Serial.print("\tRed:"); Serial.print(r);
      Serial.print("\tGreen:"); Serial.print(g);
      Serial.print("\tBlue:"); Serial.print(b);
  
    if ((r > 1.4) && (g < 0.9) && (b < 0.9)) 
    {
       color_box=1;
      color_box_t = "RED";
    }
//  else if ((r < 0.95) && (g > 1.2) && (b < 0.9)) 
    else if ((r < 0.9) && (g > 1.2) && (b < 1.2))
    {
       color_box=2;
      color_box_t = "GREEN";
// Serial.print("\tGREEN");
    }
    else if ((r < 0.8) && (g < 1.2) && (b > 0.9)) 
    {
       color_box=3;
      color_box_t = "BLUE";
// Serial.print("\tBLUE");

    }
    else if ((r > 1.15) && (g > 1.15) && (b < 0.7)) 
    {
       color_box=4;
      color_box_t = "YELLOW";
// Serial.print("\tYELLOW");
    }
 
    else if ((r < 0.8) && (g < 1.2) && (b > 0.9)) 
    {
       color_box=5;
      color_box_t = "Blak";
// Serial.print("\tBLUE");

    }
    else if ((r > 0.85) && (g < 0.95) && (b > 0.95)) 
    {
       color_box=6;
      color_box_t = "WITH";
// Serial.print("\tYELLOW");
    }
    else if ((r > 1.4) && (g < 1.0) && (b < 0.7)) 
    {
      Serial.print("\tORANGE");
    } 
    else 
    {
      color_box=7;
      color_box_t = "NONE";
      Serial.print("\tNONE"); 
    }
   
    Serial.println("");
    delay(10);
 
}

void box_val()
   {
    
  ch_color_box();  
   
   if  (color_box == 1)  
      {
          color_box_val = 1.0;
      }
   else if  (color_box == 2)
      {
          color_box_val = 2.0;  
      }
   else if  (color_box == 3)
      {
          color_box_val = 3.0;  
      } 
  else if  (color_box == 4)
      {
          color_box_val = 4.0;  
      }  
  else if  (color_box == 5)
      {
          color_box_val = 5.0;  
      } 
  else if  (color_box == 6)
      {
          color_box_val = 6.0;  
      } 
  else 
      {
          color_box_val = 7.0;  
      }  
      

      Motor(0,0,50);   
   }

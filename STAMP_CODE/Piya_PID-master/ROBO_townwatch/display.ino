


void setup_display()
{
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)

}

void read_display_test()
{ 
      
         ch_color_box();
         ch_color_floor_spi_l();
         ch_color_floor_spi_r();
         
        read_sensor_F();
        read_sensor_Bdisplay();        
        display.setTextSize(1);
        display.setTextColor(WHITE);
        
        display.setCursor(0, 0);
        display.print("A0:");
        display.println(A0,DEC);
        display.setCursor(40, 0);
        display.print("B0:");
        display.println(Z0,DEC);
        display.setCursor(80, 0);
        display.print("pa:");
        display.println(color_a);
        
        display.setCursor(0, 8);
        display.print("A1:");
        display.println(A1,DEC);
        display.setCursor(40, 8);
        display.print("B1:");
        display.println(Z1,DEC);
        display.setCursor(80, 8);
         display.print("pb:");
        display.println(color_b);
        
        display.setCursor(0, 16);
        display.print("A2:");
        display.println(A2,DEC);
        display.setCursor(40, 16);
        display.print("B2:");
        display.println(Z2,DEC);
        display.setCursor(80, 16);
       display.print("pc:");
        display.println(color_c);
        
        display.setCursor(0, 24);
        display.print("A3:");
        display.println(A3,DEC);
        display.setCursor(40, 24);
        display.print("B3:");
        display.println(Z3,DEC);
        display.setCursor(80, 24);
        display.print("box:");
        display.println(color_box);
        
        display.setCursor(0, 32);
        display.print("A4:");
        display.println(A4,DEC);
        display.setCursor(40, 32);
        display.print("B4:");
        display.println(Z4,DEC);
        display.setCursor(80, 32);
        display.print("spR:");
        display.println(color_spi_r);
        
        
        display.setCursor(0, 40);
        display.print("A5:");
        display.println(A5,DEC);
        display.setCursor(40, 40);
        display.print("B5:");
        display.println(Z5,DEC);
         display.setCursor(80, 40);
        display.print("box:");
        display.println(color_box_t);
        
        display.setCursor(0, 48);
        display.print("A6:");
        display.println(A6,DEC);
        display.setCursor(40, 48);
        display.print("B6:");
        display.println(Z6,DEC);
        display.setCursor(80, 48);
        display.print("spL:");
        display.println(color_spi_tl);
        
        display.setCursor(0, 56);
        display.print("A7:");
        display.println(A7,DEC);
        display.setCursor(40, 56);
        display.print("B7:");
        display.println(Z7,DEC);
        display.setCursor(80, 56);        
        display.print("spR:");
         display.println(color_spi_tr);


        display.display();
        delay(200);
        display.clearDisplay();
        delay(50);
        
}

void read_display()
{ 
        
         ch_color_box();
        
        read_sensor_F();
        read_sensor_Bdisplay();        
        display.setTextSize(1);
        display.setTextColor(WHITE);
        
        display.setCursor(0, 0);
        display.print("A0:");
        display.println(A0,DEC);
        display.setCursor(40, 0);
        display.print("B0:");
        display.println(Z0,DEC);
        display.setCursor(80, 0);
        display.print("PA0:");
        display.println(analogRead(PA0));
        
        display.setCursor(0, 8);
        display.print("A1:");
        display.println(A1,DEC);
        display.setCursor(40, 8);
        display.print("B1:");
        display.println(Z1,DEC);
        display.setCursor(80, 8);
        display.print("PA1:");
        display.println(analogRead(PA1));
        
        display.setCursor(0, 16);
        display.print("A2:");
        display.println(A2,DEC);
        display.setCursor(40, 16);
        display.print("B2:");
        display.println(Z2,DEC);
        display.setCursor(80, 16);
        display.print("PA2:");
        display.println(analogRead(PA2));
        
        display.setCursor(0, 24);
        display.print("A3:");
        display.println(A3,DEC);
        display.setCursor(40, 24);
        display.print("B3:");
        display.println(Z3,DEC);
        display.setCursor(80, 24);
        display.print("PA3:");
        display.println(analogRead(PA3));
        
        display.setCursor(0, 32);
        display.print("A4:");
        display.println(A4,DEC);
        display.setCursor(40, 32);
        display.print("B4:");
        display.println(Z4,DEC);
        display.setCursor(80, 32);
        display.print("PA10:");
        display.println(digitalRead(PA10));
        
        
        display.setCursor(0, 40);
        display.print("A5:");
        display.println(A5,DEC);
        display.setCursor(40, 40);
        display.print("B5:");
        display.println(Z5,DEC);
         display.setCursor(80, 40);
        display.print("PA11:");
        display.println(digitalRead(PA11));
        
        display.setCursor(0, 48);
        display.print("A6:");
        display.println(A6,DEC);
        display.setCursor(40, 48);
        display.print("B6:");
        display.println(Z6,DEC);
        display.setCursor(80, 48);
        display.print("BOX:");
        display.println(color_box_t);
        
        display.setCursor(0, 56);
        display.print("A7:");
        display.println(A7,DEC);
        display.setCursor(40, 56);
        display.print("B7:");
        display.println(Z7,DEC);
        display.setCursor(80, 56);        
        display.print("FLO:");
        display.println( color_floor_t);

        display.display();
        delay(200);
        display.clearDisplay();
        delay(50);
        
}


void read_display_spi()
{ 
        ch_color_box() ;
        // ch_color_floor_spi();
        
        read_sensor_F();
        read_sensor_Bdisplay();        
        display.setTextSize(1);
        display.setTextColor(WHITE);
        
        display.setCursor(0, 0);
        display.print("A0:");
        display.println(A0,DEC);
        display.setCursor(40, 0);
        display.print("B0:");
        display.println(Z0,DEC);
        display.setCursor(80, 0);
        display.print("PA0:");
        display.println(analogRead(PA0));
        
        display.setCursor(0, 8);
        display.print("A1:");
        display.println(A1,DEC);
        display.setCursor(40, 8);
        display.print("B1:");
        display.println(Z1,DEC);
        display.setCursor(80, 8);
        display.print("PA1:");
        display.println(analogRead(PA1));
        
        display.setCursor(0, 16);
        display.print("A2:");
        display.println(A2,DEC);
        display.setCursor(40, 16);
        display.print("B2:");
        display.println(Z2,DEC);
        display.setCursor(80, 16);
        display.print("PA2:");
        display.println(analogRead(PA2));
        
        display.setCursor(0, 24);
        display.print("A3:");
        display.println(A3,DEC);
        display.setCursor(40, 24);
        display.print("B3:");
        display.println(Z3,DEC);
        display.setCursor(80, 24);
        display.print("PA3:");
        display.println(analogRead(PA3));
        
        display.setCursor(0, 32);
        display.print("A4:");
        display.println(A4,DEC);
        display.setCursor(40, 32);
        display.print("B4:");
        display.println(Z4,DEC);
        display.setCursor(80, 32);
        display.print("PA10:");
        display.println(digitalRead(PA10));
        
        
        display.setCursor(0, 40);
        display.print("A5:");
        display.println(A5,DEC);
        display.setCursor(40, 40);
        display.print("B5:");
        display.println(Z5,DEC);
         display.setCursor(80, 40);
        display.print("PA11:");
        display.println(digitalRead(PA11));
        
        display.setCursor(0, 48);
        display.print("A6:");
        display.println(A6,DEC);
        display.setCursor(40, 48);
        display.print("B6:");
        display.println(Z6,DEC);
        display.setCursor(80, 48);
        display.print("BOX:");
        display.println(color_box_t);
        
        display.setCursor(0, 56);
        display.print("A7:");
        display.println(A7,DEC);
        display.setCursor(40, 56);
        display.print("B7:");
        display.println(Z7,DEC);
        display.setCursor(80, 56);        
        display.print("FLO:");
        display.println( color_spi_t);

        display.display();
        delay(200);
        display.clearDisplay();
        delay(50);
        
}

void read_display_spi_2color()
{ 
      
         ch_color_box();
         ch_color_floor_spi_l() ;
         ch_color_floor_spi_r() ;

         
        read_sensor_F();
        read_sensor_Bdisplay();        
        display.setTextSize(1);
        display.setTextColor(WHITE);
        
        display.setCursor(0, 0);
        display.print("A0:");
        display.println(A0,DEC);
        display.setCursor(40, 0);
        display.print("B0:");
        display.println(Z0,DEC);
        display.setCursor(80, 0);
        display.print("PA1:");
        display.println(analogRead(PA1));
        
        display.setCursor(0, 8);
        display.print("A1:");
        display.println(A1,DEC);
        display.setCursor(40, 8);
        display.print("B1:");
        display.println(Z1,DEC);
        display.setCursor(80, 8);
        display.print("PA2:");
        display.println(analogRead(PA2));
        
        display.setCursor(0, 16);
        display.print("A2:");
        display.println(A2,DEC);
        display.setCursor(40, 16);
        display.print("B2:");
        display.println(Z2,DEC);
        display.setCursor(80, 16);
        display.print("PA3:");
        display.println(analogRead(PA3));
        
        display.setCursor(0, 24);
        display.print("A3:");
        display.println(A3,DEC);
        display.setCursor(40, 24);
        display.print("B3:");
        display.println(Z3,DEC);
        display.setCursor(80, 24);
        display.print("PA10:");
        display.println(digitalRead(PA10));
        
        display.setCursor(0, 32);
        display.print("A4:");
        display.println(A4,DEC);
        display.setCursor(40, 32);
        display.print("B4:");
        display.println(Z4,DEC);
        display.setCursor(80, 32);
        display.print("PA11:");
        display.println(digitalRead(PA11));
        
        
        display.setCursor(0, 40);
        display.print("A5:");
        display.println(A5,DEC);
        display.setCursor(40, 40);
        display.print("B5:");
        display.println(Z5,DEC);
         display.setCursor(80, 40);
        display.print("box:");
        display.println(color_box_t);
        
        display.setCursor(0, 48);
        display.print("A6:");
        display.println(A6,DEC);
        display.setCursor(40, 48);
        display.print("B6:");
        display.println(Z6,DEC);
        display.setCursor(80, 48);
        display.print("spL:");
        display.println(color_spi_tl);
        
        display.setCursor(0, 56);
        display.print("A7:");
        display.println(A7,DEC);
        display.setCursor(40, 56);
        display.print("B7:");
        display.println(Z7,DEC);
        display.setCursor(80, 56);        
        display.print("spR:");
        display.println(color_spi_tr);

        display.display();
        delay(200);
        display.clearDisplay();
        delay(50);
        
}

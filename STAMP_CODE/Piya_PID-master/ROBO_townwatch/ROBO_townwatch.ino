//http://dan.drown.org/stm32duino/package_STM32duino_index.json
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MCP3008.h>
#include "Piya_color.h"


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
Piya_color tcs = Piya_color(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_1X);
Adafruit_MCP3008 adc;


//////////////////////////////////////////กำหนดของควบคุมมอเตอร์
#define PWMR  PA9  //   motor R
#define IN1R  PB15  //  
#define IN2R  PB14  //

#define PWML  PA8  //   motor L
#define IN1L  PC15  //  
#define IN2L  PB13  //

float X;
float Y;
float Z;
float U;
float V;
float W; 





////////////////////////////////////กำหนดตัวแปลของเซนเซอร์
int A0 = 0;
int A1 = 0;
int A2 = 0;
int A3 = 0;
int A4 = 0;
int A5 = 0;
int A6 = 0;
int A7 = 0;

int Z0 = 0;
int Z1 = 0;
int Z2 = 0;
int Z3 = 0;
int Z4 = 0;
int Z5 = 0;
int Z6 = 0;                
int Z7 = 0;
 ////////////////////////////////////กำหนดขา SPI
int i = PA5;  // ขา clk
int j = PA6;  // ขา miso 
int k = PA7; // ขา mosi 
int m = PA4; // ขา cs 1
int n = PB12; // ขา cs 2

int T=0;
int t=0;
int set_T = 0;
int SP_BEGIN = 0;




const int buttonPin = PC14;

////////////////////////////////////ค่าตัวแปรที่แสดง ในรูปของ text
String color_box_t;
String color_floor_t;
String color_spi_t;
String color_spi_tl;
String color_spi_tr;

////////////////////////////////////ค่าตัวแปรที่แสดง ในรูปของ number
int color_box;
int color_floor;
int color_spi;
int color_spi_l;
int color_spi_r;

 ///////////////////////ตัวแปรเก็บค่าสีพื้น ที่อ่านจาก SPI เรียงลำดับจากพื้นสี
float color_a;
float color_b;
float color_c;
float color_d;
float color_e;


float color_box_val;   //////////ตัวแปรเก็บค่าสีกล่อง ที่อ่านจาก color_box 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int c_l = 40;   ////////////////กำหนดความเร็วในการเลี้ยวซ้ายแบบกลางล้อ
int c_r = 40;   ////////////////กำหนดความเร็วในการเลี้ยวขวาแบบกลางล้อ

int f_l = 65;   ////////////////กำหนดความเร็วในการเลี้ยวซ้าย แบบหน้าล้อ
int f_r = 65;   ////////////////กำหนดความเร็วในการเลี้ยวขวา แบบหน้าล้อ

int bc_l = 40;  ////////////////กำหนดความเร็วในการเลี้ยวซ้ายแบบกลางล้อ ถอยหลัง
int bc_r = 40;  ////////////////กำหนดความเร็วในการเลี้ยวขวาแบบกลางล้อ ถอยหลัง

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float KP_SL = 10;  /////////////ตัวแปร KP ของสปีดต้น
float KD_SL = 120;

float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0,previous_I=0;




void setup() {
  //setup_TCS34725();
  setup_spi();
  setup_BUZZER();
  setup_display();
  setup_servo();
  
 
  BZ(50);
  LD(50);
  BZ(50);
  LD(50);
  S_UP(); 
  servo_small(); 
  delay(500);
  digitalWrite(PC13,LOW); 
  delay(10);
  
        display.display();
        delay(200);
        display.clearDisplay();
        delay(50);
   S_UP(); 
   
   servo_kang();
   keep() ;
 
  while(digitalRead(PC14)==HIGH){read_display_spi_2color();}
  
  BZ(500);

//เขียนโค๊ดที่นี้
////////////////////////////////////////////
  //box_1();
   //fline (40 ,40,5, 10, 'c',15 ); 
   colorline (20 ,20, 10, 'r','c', 10);

  Motor(0,0,2); 
  delay(1000);
  while(digitalRead(PC14)==HIGH){read_display_spi_2color();}
/*
read_sensor_B();
    
         while(1)
             {    
                read_sensor_values_B();
                P = error;
                I = I + previous_I;
                D = error - previous_error;    
                PID_value = (5*P) + (0.0015*I) + (15*D);     
                previous_I=I;  
                previous_I=I;
                previous_error=error;
                Motor(-(30 - PID_value),-(30 + PID_value)); 
              if 
                ((A0<200)&&(A3<200)&&(A4<200)&&(A7<200)
                ||(A0<200)&&(A2<200)
                ||(A0<200)&&(A3<200)
                ||(A0<200)&&(A4<200)
                ||(A7<200)&&(A4<200)
                ||(A7<200)&&(A5<200)
                ||(A7<200)&&(A3<200))       
         
                  break;
             }
       Motor(20,20,2);
       Motor(0,0,1);

*/
   
//////////////////////////////////////////////
//จบการเขียนโค๊ด

 /*BZ(50);
  LD(50);
  BZ(50);
  LD(50);*/
}

void loop() {
  
 




}

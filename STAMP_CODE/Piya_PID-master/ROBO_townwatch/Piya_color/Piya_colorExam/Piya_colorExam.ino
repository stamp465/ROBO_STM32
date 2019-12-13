#include "Piya_color.h"
 uint16_t r, g, b, c;
 uint16_t color = 0;
/* Connect SCL    to PB6
   Connect SDA    to PB7
   Connect VDD    to 5V DC
   Connect GROUND to common ground
   PiyamaharachalaiSchool www.piya.ac.th
 */ 
Piya_color tcs = Piya_color(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_1X);
void setup(void) {
  Serial.begin(9600);
  if(tcs.begin());
}
void loop(void) {
  tcs.getRawData(&r, &g, &b, &c);
  if(g > 0) {
    if(g>800) {color = 4;}
    else if(g>620) {color = 3;}
    else if(g>350) {color = 2;}
    else if(g>250) {color = 5;}
    else {color = 1;}
  }
  if(color == 1){
    Serial.println("Red");
  }
  if(color == 2){
    Serial.println("Green");
  }
   if(color == 3){
    Serial.println("Gray");
  }
   if(color == 4){
    Serial.println("Yellow");
  }
   if(color == 5){
    Serial.println("Magenta");
  }
  /*Serial.print("R: "); Serial.print(r); Serial.print(" ");
  Serial.print("G: "); Serial.print(g); Serial.print(" ");
  Serial.print("B: "); Serial.print(b); Serial.print(" ");
  Serial.print("C: "); Serial.print(c); Serial.print(" ");
  Serial.println(" ");*/
}

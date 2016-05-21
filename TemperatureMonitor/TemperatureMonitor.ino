
#include "rgb_lcd.h"
#include <Wire.h>


const int pinTemp = A0;
const int chipSelect = 2;
float temp;
int B = 3975;
float resistance;
rgb_lcd lcd;

void setup() {
  // put your setup code here, to run once:
  pinMode(chipSelect, OUTPUT); 
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.print("Temperature");
  Serial.print("Swati is a noob");
  
}


void changeColor (unsigned char color) {
  for (int i = 0; i < 255; i++) {
    lcd.setPWM(color, i);
    delay(5);
  }
  delay(500);
  for (int i = 254; i >= 0 ; i--) {
    lcd.setPWM(color, i);
    delay(5);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int val = analogRead(pinTemp);                               // get analog value
  Serial.print(val);
  lcd.print(val);
  resistance = (float)(1023 - val) * 10000 / val;              // get resistance
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
  temp = 1 / (log(resistance / 10000) / B + 1 / 298.15) - 273.15; // calc temperature
  lcd.print("It is ");           // Print "it is" on the screen
  lcd.print(temp);          // Print the final temperature
  lcd.print(" *C");            // Add *c on the En
  delay(1000);          // delay 1s
  lcd.clear();            //Clear the screen and loop
/*
digitalWrite(led, HIGH); 
delay(1000); 
digitalWrite(led, LOW); 
delay(1000); 
*/
}




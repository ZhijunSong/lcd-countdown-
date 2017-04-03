#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
int days= 1379;
int hours = 2; // start hours
int minutes = 42; //start min
int seconds = 28; 
LiquidCrystal_I2C  lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the I2C bus address for an unmodified module

void setup()
{
    lcd.setBacklightPin(3,POSITIVE);
    lcd.setBacklight(HIGH); // NOTE: You can turn the backlight off by setting it to LOW instead of HIGH
    lcd.begin(16, 2);
    lcd.clear();
}

void loop()
{
    //lcd.print("Count Down Timer ");
 
 // lcd.scrollDisplayLeft();
 // wait a bit:
 //1`delay(150);
 
 while (days>=0 ||hours > 0 || minutes > 0 || seconds >= 0) {
 
 lcd.setCursor(3, 2);
  (days < 10) ? lcd.print("0") : NULL;
 lcd.print(days);
 lcd.print(":");
 (hours < 10) ? lcd.print("0") : NULL;
 lcd.print(hours);
 lcd.print(":");
 (minutes < 10) ? lcd.print("0") : NULL;
 lcd.print(minutes);
 lcd.print(":");
 (seconds < 10) ? lcd.print("0") : NULL;
 lcd.print(seconds);
 lcd.display();
 stepDown();
 delay(1000);
 }
}
void stepDown() {
 if (seconds > 0) {
 seconds -= 1;
 } else {
   if (minutes > 0) {
      seconds = 59;
      minutes -= 1;
    } else {
        if (hours > 0) {
            seconds = 59;
            minutes = 59;
            hours -= 1;
        } else {
            if (days > 0) {
            seconds = 59;
            minutes = 59;
            hours -= 1;
            days-=1;
                }else {
                   trigger();
                       }
                }
         }
 }
}
 
void trigger() {
 lcd.clear(); // clears the screen and buffer
 lcd.setCursor(5, 1); // set timer position on lcd for end.
 
 lcd.println("END ");
 delay(1000);
 
 lcd.display();
}

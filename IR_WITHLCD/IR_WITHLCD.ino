//www.elegoo.com
//2016.12.9

/*
  LiquidCrystal Library - Hello World

  Demonstrates the use of a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the
  Hitachi HD44780 driver. There are many of them out there, and you
  can usually tell them by the 16-pin interface.

  This sketch prints "Hello World!" to the LCD
  and shows the time.

  The circuit:
   LCD RS pin to digital pin 7
   LCD Enable pin to digital pin 8
   LCD D4 pin to digital pin 9
   LCD D5 pin to digital pin 10
   LCD D6 pin to digital pin 11
   LCD D7 pin to digital pin 12
   LCD R/W pin to ground
   LCD VSS pin to ground
   LCD VCC pin to 5V
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)

  Library originally added 18 Apr 2008
  by David A. Mellis
  Library modified 5 Jul 2009
  by Limor Fried (http://www.ladyada.net)
  Example added 9 Jul 2009
  by Tom Igoe
  Modified 22 Nov 2010
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/

// include the library code:
#include <LiquidCrystal.h>
#include<IRremote.h>
#include "IR.h"
#define DT 1000
int rec_pin = 5;
IRrecv IR(rec_pin); //PIN 11 ON ARDUINO
decode_results CMD;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
String lcd_pad;

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd_pad = "mosse !!";
  lcd.print(lcd_pad);
  IR.enableIRIn();
  delay(DT);
  lcd.clear();
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  int rem_value;
  if (IR.decode(&CMD)) {

    for (int i = 0; i < 24; i++) {

      if (keyValue[i] == CMD.value && (i < KEY_NUM)) { //CONSITION FOR OUR FOR LOOP TO BE FOR A SECIFIC PURPOSE KEY_NUM=21

        Serial.println(keyBuf[i]); // IR.h library 2 dimension char array with natural language naming
        rem_value = CMD.value; // to over write the value of result or remote signal before receiving another signal
        if (keyValue[i] == KEY_POWER) {
          lcd_pad = "POWER";
          lcd.print(lcd_pad);
          lcd.setCursor(0, 1);
          // print the number of seconds since reset:
          lcd.print(millis() / 1000);
          delay(DT);
          lcd.clear();
        } else if (keyValue[i]== KEY_FUNC_STOP) {
          lcd_pad = "function";
          lcd.print(lcd_pad);
          lcd.setCursor(0, 1);
          // print the number of seconds since reset:
          lcd.print(millis() / 1000);
          delay(DT);
          lcd.clear();
        } else if (keyValue[i]== KEY_UP) {
          lcd_pad = "up";
          lcd.print(lcd_pad);
          lcd.setCursor(0, 1);
          // print the number of seconds since reset:
          lcd.print(millis() / 1000);
          delay(DT);
          lcd.clear();
        }else{
          lcd_pad="not working hhhe";
          lcd.setCursor(0,0);
          lcd.print(lcd_pad);
          lcd.setCursor(0,1);
          lcd.print(millis()/1000);
          delay(DT);
          lcd.clear();
          }

      } else if (REPEAT == i)
      {
        CMD.value = rem_value;
      }
    }
    IR.resume(); // receive the next value
  }
}

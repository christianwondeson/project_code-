//www.elegoo.com
//2016.12.9

#include "SR04.h"

#define trig_pin 2
#define echo_pin 3
#define delayT 3000

SR04 dis = SR04(echo_pin, trig_pin);
int tDelay = 200;
int latchPin = 11;      // (11) ST_CP [RCK] on 74HC595
int clockPin = 9;      // (9) SH_CP [SCK] on 74HC595
int dataPin = 12;     // (12) DS [S1] on 74HC595
long distance;
byte leds = 0;
void dd();
/*   The most common method of using 74CH595
     lctchPin->LOW : Begin transmitting signals.
     shiftOut(dataPin, clockPin, bitOrder, value)
     dataPin: the pin on which to output each bit. Allowed data types: int.
     clockPin: the pin to toggle once the dataPin has been set to the correct value. Allowed data types: int.
     bitOrder: which order to shift out the bits; either MSBFIRST or LSBFIRST. (Most Significant Bit First, or, Least Significant Bit First).
     value: the data to shift out. Allowed data types: byte.
     lctchPin->HIch : The end of the transmission signal.
*/
void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("measuring distance !!");
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop()
{
  //Turn off all led
  leds = 0;
  updateShiftRegister();
  delay(tDelay);
  distance = dis.Distance();

  Serial.print(distance);
  Serial.println("cm");

  for (int i = 0; i < 8; i++)  //Create a for loop:i 0 through 7 have gradually increased
  {
    //turn on the led with the i transform
    if (i <= 7 && (distance >= 25 && distance <=35)) {
      leds = 0;
      bitSet(leds, i);
      updateShiftRegister();
      delay(tDelay);
      if (i == 3)
      {
        dd();
        break;
      }
    } if (i <= 7 && (distance < 25 && distance > 10)) {
      leds = 0;
      bitSet(leds, i);
      updateShiftRegister();
      delay(tDelay);
      if (i == 5)
      {
        dd();
        break;
      }
    } else if (i <= 7 && (distance <= 10))
    {
      leds = 0;
      bitSet(leds, i);
      updateShiftRegister();
      delay(tDelay);
      if (i == 7)
      {
        dd();
        break;
      }
    } else
      {
        leds = 0;
        bitSet(leds, i);
        updateShiftRegister();
        delay(tDelay);
        if (i <=2 && (distance > 35))
    {
      dd();
      break;
    }
      }
  }
}
void dd()
 {
  delay(delayT);
  }

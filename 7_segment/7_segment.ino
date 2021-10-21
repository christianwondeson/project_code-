//www.elegoo.com
//2016.12.12

// define the LED digit patterns, from 0 - 9
// 1 = LED on, 0 = LED off, in this order:
//                74HC595 pin     Q0,Q1,Q2,Q3,Q4,Q5,Q6,Q7
//                Mapping to      a,b,c,d,e,f,g of Seven-Segment LED
#include "IRremote.h"
#include "IR.h"

IRrecv irrecv(RECEIVER);     // create instance of 'irrecv' to receive data from pin 11 on the arduino
decode_results results;      // create instance of 'decode_results'
//using decode_results class for decoding remote
byte seven_seg_digits[11] = { B11111100,  // = 0
                              B01100000,  // = 1
                              B11011010,  // = 2
                              B11110010,  // = 3
                              B01100110,  // = 4
                              B10110110,  // = 5
                              B10111110,  // = 6
                              B11100000,  // = 7
                              B11111110,  // = 8
                              B11100110,   // = 9
                              B10011110
                            };

// connect to the ST_CP of 74HC595 (pin 3,latch pin)
int latchPin = 3;
// connect to the SH_CP of 74HC595 (pin 4, clock pin)
int clockPin = 4;
// connect to the DS of 74HC595 (pin 2)
int dataPin = 2;

void setup() {
  // Set latchPin, clockPin, dataPin as output
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

// display a number on the digital segment display
byte sevenSegWrite(byte digit) {
  // set the latchPin to low potential, before sending data
  digitalWrite(latchPin, LOW);

  // the original data (bit pattern)
  shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);

  // set the latchPin to high potential, after sending data
  digitalWrite(latchPin, HIGH);
  return digit;
}

 void counter()
  {
    
    for (byte digit = 10; digit > 0; --digit) {
    //delay(3000);
    if(keyValue[digit+10]== KEY_POWER)
      {
        Serial.println("you entered");
        Serial.println(keyValue[digit],HEX);
        sevenSegWrite(digit);
      }
   // sevenSegWrite(digit - 1);
  }
  // suspend 4 seconds
  //delay(3000);
  } 

void loop() {
  // count from 9 to 0
  int input;
  int delays = 1000;
  int tmpValue;
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    for (int i = 0; i < 23; i++)
    {
      if ((keyValue[i] == results.value) && (i < KEY_NUM))
      {
        counter();
        Serial.println(keyBuf[i]);
        tmpValue = results.value;

        

        if (keyValue[i] == KEY_3) {  //condition for the IR to find power button

          Serial.println(keyValue[i], HEX);
          sevenSegWrite(3);

        } else if (keyValue[i] == KEY_1) {

          Serial.println(keyValue[i], HEX);
          sevenSegWrite(1);
          

        } else if (keyValue[i] == KEY_2) {

          Serial.println(keyValue[i], HEX);
          sevenSegWrite(2);
        }else if (keyValue[i] == KEY_POWER) {

          Serial.println(keyValue[i], HEX);
          sevenSegWrite(11);
        }else if (keyValue[i] == KEY_4) {

          Serial.println(keyValue[i], HEX);
          sevenSegWrite(4);
        }else if (keyValue[i] == KEY_POWER) {

          Serial.println(keyValue[i], HEX);
          sevenSegWrite(10);
        }
      }
      else if (REPEAT == i)
      {
        results.value = tmpValue;
      }
    }
    irrecv.resume();
  }
}

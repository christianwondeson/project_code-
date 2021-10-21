//www.elegoo.com
//2016.12.08
#include "SR04.h"  //must include HC-SR04 library 
#define TRIG_PIN 8
#define ECHO_PIN 9

//create a color pin constant

#define RED 11
#define GREEN 5
#define BLUE 3


SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN); //user defined library object that takes two arguments
long a;

void setup() {

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
  delay(100);
}
int redvalue = 0;
int greenvalue = 0;
// int yellowvalue=0;

#define delayT 10

void loop() {
  a = sr04.Distance();
  if (a < 10) {
    redvalue = 25;
    Serial.print(a);
    Serial.println("cm");
    Serial.println("danger !!");

    for (int i = 0; i < 25; i++) {
     setColor(25, 0, 0);
      delay(delayT);
    }
  }
  else if (a >= 10 && a <= 27) {
    Serial.print(a);
    Serial.println("cm");
    Serial.println("be aware !!");
     for(int i=0; i<255; i++){
    setColor(255, 255, 0);
        delay(delayT);
       }
  } else if (a > 27) {
    greenvalue = 25;
    Serial.print(a);
    Serial.println("cm");
    Serial.println("safe zone");
    for (int i = 0; i < 25; i++) {
     setColor(0, 25, 0);
      delay(delayT);
    }
  }
  delay(1000);
}

void setColor(int red, int green, int blue) {

  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
}

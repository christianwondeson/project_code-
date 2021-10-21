//www.elegoo.com
//2016.12.12

/************************
Exercise the motor using
the L293D chip
************************/
#include "DHT.h"
#define sensor_type DHT11
#define ENABLE 5
#define DIRA 3
#define DIRB 4
#define delays 500
int i;
int delay_start=1000;
int pin_type = 2; 
float tempC;
float tempF;
float humidity;
DHT HT(pin_type,sensor_type);
void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
  HT.begin();
  delay(delay_start);
}

void loop() {

   humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);

  Serial.print("HUMIDITY :");
  Serial.print(humidity);
  Serial.print("%");
  Serial.print(" | ");
  Serial.print("TEMPERATURE :");
  Serial.print(tempC );
  Serial.print("°C");
  Serial.print(" | ");
  Serial.print("TEMPERATURE :");
  Serial.print(tempF );
  Serial.print("℉");
  Serial.println("");
  
  //---back and forth example

  if(tempC<=1){
   // Serial.println("One way, then reverse");
    digitalWrite(ENABLE,HIGH); // enable on
    for (i=0;i<5;i++) {
    digitalWrite(DIRA,HIGH); //one way
    digitalWrite(DIRB,LOW);
    delay(1000);
    }
  }else 
  {
    digitalWrite(DIRB,HIGH);
    digitalWrite(DIRB,LOW);
    delay(2000);
  } 
   /* digitalWrite(DIRA,LOW);  //reverse
    digitalWrite(DIRB,HIGH);
    delay(3000);*/
 /* digitalWrite(ENABLE,LOW); // disable
  delay(7000);

  Serial.println("fast Slow example");
  //---fast/slow stop example
  digitalWrite(ENABLE,HIGH); //enable on
  digitalWrite(DIRA,HIGH); //one way
  digitalWrite(DIRB,LOW);
  delay(8000);
  digitalWrite(ENABLE,LOW); //slow stop
  delay(1000);
  digitalWrite(ENABLE,HIGH); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
  delay(5000);
  digitalWrite(DIRA,LOW); //fast stop
  delay(2000);

  Serial.println("PWM full then slow");
  //---PWM example, full speed then slow
  analogWrite(ENABLE,255); //enable on
  digitalWrite(DIRA,HIGH); //one way
  digitalWrite(DIRB,LOW);
  delay(5000);
  analogWrite(ENABLE,180); //half speed
  delay(5000);
  analogWrite(ENABLE,128); //half speed
  delay(5000);
  analogWrite(ENABLE,50); //half speed
  delay(5000);
  analogWrite(ENABLE,128); //half speed
  delay(5000);
  analogWrite(ENABLE,180); //half speed
  delay(5000);
  analogWrite(ENABLE,255); //half speed
  delay(5000);
  digitalWrite(ENABLE,LOW); //all done
  delay(10000);*/
}
   

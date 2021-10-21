#include "IRremote.h"
#include "IR.h"
#define enable 5
#define directa 3
#define directb 4
#define delay_1 300
int interval = 2000;
int pin_Mode = 6;
IRrecv recieve (pin_Mode);
decode_results results;
void setup() {
  // put your setup code here, to run once:
  pinMode(enable, OUTPUT);
  pinMode(directa, OUTPUT);
  pinMode(directb, OUTPUT);
  Serial.begin(9600);
  Serial.println("IR recieving !!");
  recieve.enableIRIn();
  delay(delay_1);
}

void loop() {
  // put your main code here, to run repeatedly:
  int next_value;
  if (recieve.decode(&results)) {
    for (int i = 0; i < 23; i++) {
      if ((keyValue[i] == results.value) && (i < KEY_NUM))
      {
        Serial.println(keyBuf[i]);
        next_value = results.value;

        if (keyValue[i] == KEY_POWER)
        {
          Serial.println("One way, then reverse");
          digitalWrite(enable, HIGH); // enable on
          for (i = 0; i < 5; i++) {
            digitalWrite(directa, HIGH); //one way
            digitalWrite(directb, LOW);
            delay(500);
            digitalWrite(directa, LOW); //reverse
            digitalWrite(directb, HIGH);
            delay(500);
          }
        } else if (keyValue == KEY_FAST_FORWARD)
        {
          Serial.println(keyValue[i], HEX);
          digitalWrite(enable, HIGH);
          for (int i = 0; i < 5; i++) {
            digitalWrite(directa, HIGH);
            digitalWrite(directa, LOW);
            delay(interval);
          }
        } else if (keyValue == KEY_PAUSE)
        {
          Serial.println(keyValue[i], HEX);
          digitalWrite(enable, HIGH);
          digitalWrite(directa, LOW);
          digitalWrite(directb, LOW);
          //delay(interval);
        } else if (keyValue == KEY_FAST_BACK)
        {
          Serial.println(keyValue[i], HEX);
          digitalWrite(enable, HIGH);
          digitalWrite(directb, HIGH);
          digitalWrite(directb, LOW);
          //delay(interval);
        }
      } else if (REPEAT == i)
      {
        results.value = next_value;
      }
    }

    recieve.resume();
  }
}

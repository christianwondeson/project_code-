//www.elegoo.com
//2020.3.12

#include "IRremote.h"
#include "IR.h"
#define RED 3
#define GREEN 5
#define BLUE  6

IRrecv irrecv(RECEIVER);     // create instance of 'irrecv' to receive data from pin 11 on the arduino
decode_results results;      // create instance of 'decode_results'
bool ledstate; //state of the led defined in bool
int DT = 100;
void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
  ledstate = false;
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  digitalWrite(RED,ledstate);
  digitalWrite(GREEN,ledstate);
  digitalWrite(BLUE,ledstate);
  
}
#define buz_delay 1000
void loop()
{
  int tmpValue;
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    for (int i = 0; i < 23; i++)
    {
      if ((keyValue[i] == results.value) && (i < KEY_NUM))
      {
        Serial.println(keyBuf[i]);
        tmpValue = results.value;

        if (keyValue[i] == KEY_POWER) {  //condition for the IR to find power button
          ledstate = !ledstate; //set the ledstate to true bool value
        //  digitalWrite(LED_BUILTIN, ledstate);
        setColor(0,0,0);
          delay(DT);
        }
        else if (keyValue[i] == KEY_1) {
           ledstate=!ledstate;
           analogWrite(RED,HIGH);
          setColor(25, 0, 0);
          Serial.println(keyValue[i], HEX);
        } else if (keyValue[i] == KEY_2) {

          Serial.println(keyValue[i], HEX);
          setColor(0, 25, 0);
        } else if (keyValue[i] == KEY_3) {

          Serial.println(keyValue[i], HEX);
          setColor(0, 0, 25);
          delay(buz_delay);
        }

      }
      else if (REPEAT == i)
      {
        results.value = tmpValue;
      }
    }
    irrecv.resume(); // receive the next value
  }


  //The implementation effect of the above program is
  //the same as that of the following, but it is more concise

  //    switch(results.value)
  //  {
  //  case 0xFFA25D: Serial.println("POWER"); break;
  //  case 0xFFE21D: Serial.println("FUNC/STOP"); break;
  //  case 0xFF629D: Serial.println("VOL+"); break;
  //  case 0xFF22DD: Serial.println("FAST BACK");    break;
  //  case 0xFF02FD: Serial.println("PAUSE");    break;
  //  case 0xFFC23D: Serial.println("FAST FORWARD");   break;
  //  case 0xFFE01F: Serial.println("DOWN");    break;
  //  case 0xFFA857: Serial.println("VOL-");    break;
  //  case 0xFF906F: Serial.println("UP");    break;
  //  case 0xFF9867: Serial.println("EQ");    break;
  //  case 0xFFB04F: Serial.println("ST/REPT");    break;
  //  case 0xFF6897: Serial.println("0");    break;
  //  case 0xFF30CF: Serial.println("1");    break;
  //  case 0xFF18E7: Serial.println("2");    break;
  //  case 0xFF7A85: Serial.println("3");    break;
  //  case 0xFF10EF: Serial.println("4");    break;
  //  case 0xFF38C7: Serial.println("5");    break;
  //  case 0xFF5AA5: Serial.println("6");    break;
  //  case 0xFF42BD: Serial.println("7");    break;
  //  case 0xFF4AB5: Serial.println("8");    break;
  //  case 0xFF52AD: Serial.println("9");    break;
  //  case 0xFFFFFFFF: Serial.println(" REPEAT");break;
  //  default:
  //    Serial.println(" other button   ");

}// End Case

void setColor(int red, int green, int blue) {

  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);

}

//www.elegoo.com
//2016.12.08
/*****************************************/

#define RED 6
#define BLUE 9
#define GREEN 10
//int ledPin = 11;//the led attach to

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, HIGH);
  pinMode(BLUE, LOW);
  pinMode(GREEN, LOW);
  //pinMode(ledPin, OUTPUT); //initialize the ledPin as an output
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
}
/******************************************/
int redvalue;
int bluevalue;
int greenvalue;
void loop()
{
#define delayTime 1
  int redvalue = 255;
  int bluevalue = 0;
  int greenvalue = 0;
  int digitalVal = digitalRead(2);
  if (HIGH == digitalVal)
  {
    digitalWrite(redvalue, LOW); //turn the led off
    digitalWrite(bluevalue, LOW);
    digitalWrite(greenvalue, LOW);

  }
  else
  {

    //digitalWrite(ledPin, HIGH); //turn the led on
    for (int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
    {
      redvalue -= 1;
      //greenvalue += 1;
      // The following was reversed, counting in the wrong directions
      analogWrite(RED, 255 - redvalue);
      //break;
      /*
      analogWrite(GREEN, 255 - greenvalue);
      analogWrite(RED, redvalue);
      analogWrite(GREEN, greenvalue);*/
      delay(delayTime);
    }
  }
}
/**********************************************/

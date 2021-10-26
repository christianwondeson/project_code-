//www.elegoo.com
//2016.12.12

int latch = 9; //74HC595  pin 9 STCP
int clock = 10; //74HC595  pin 10 SHCP
int data = 8; //74HC595  pin 8 DS
#define dt 500
int x_axis = 0;
int y_axis = 1; //they are analog inputs
#define sw 2

void analog_joy();
unsigned char table[] =
{ 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c
  , 0x39, 0x5e, 0x79, 0x71, 0x00
};

void setup() {
  Serial.begin(9600);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(sw, INPUT);
  pinMode(sw, LOW);
}

void Display(unsigned char num)
{

  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, table[num]);
  digitalWrite(latch, HIGH);

}
void loop()
{
  int i;
  analog_joy();
  for (i = 0; i < 10; i++)
  {

    if ((i % 2) == 0)
    {
      Display(i);
      Serial.print("this are even numbers :");
      Serial.println(i);
      delay(600);

    }

  }
  Serial.print("this is done :");
  Serial.println(i);
  delay(1000);

}
void analog_joy() {

  Serial.print("switch on/off :");
  Serial.println(digitalRead(sw));
  delay(1000);

  Serial.print("x :");
  Serial.println(analogRead(x_axis));
  delay(1000);

  Serial.print("y :");
  Serial.println(analogRead(y_axis));
  delay(1000);

  while (x_axis == 0)
  {
    Serial.println("both has the same value !!");
    Serial.println(x_axis, y_axis);
    break;
  }

}

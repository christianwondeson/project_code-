
int ledPin = 3;
int pushButton1 = 4;
int pushButton2 = 10;

byte led = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(pushButton1, INPUT_PULLUP);
  pinMode(pushButton2, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(pushButton1) == LOW)
  {
    digitalWrite(ledPin, HIGH);
  } if (digitalRead(pushButton2) == LOW)
  {
    digitalWrite(ledPin, LOW);
  }
}

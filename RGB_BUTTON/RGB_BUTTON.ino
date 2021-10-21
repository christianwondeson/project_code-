#define RED 3
#define GREEN 5
#define BLUE 6

int push_B_R = 9;
int push_B_G = 10;
int push_B_B = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, LOW);
  pinMode(GREEN, LOW);
  pinMode(BLUE, LOW);
  pinMode(push_B_R, INPUT_PULLUP);
  pinMode(push_B_G, INPUT_PULLUP);
  pinMode(push_B_B, INPUT_PULLUP);

}
  int redvalue;
  int greenvalue;
  int bluevalue;
void loop() {
  #define delayTime 100
  // put your main code here, to run repeatedly:
  
  if (digitalRead(push_B_R) == LOW)
  {
     redvalue=25;
    for(int i=0; i<25; i++){
    redvalue-=1;
   analogWrite(RED,redvalue);
   delay (delayTime);
    }
  }
  
   if (digitalRead(push_B_G) == LOW)
  {
    greenvalue=25;
    for(int i=0; i<25;i++){
      greenvalue-=1;
    analogWrite(GREEN,greenvalue);
    delay(delayTime);
    }
  }
  if (digitalRead(push_B_B) == LOW)
  {
    bluevalue=25;
    for(int i=0;i<25;i++){
      bluevalue-=1;
    analogWrite(BLUE,bluevalue);
    delay(delayTime);
    }
  }

}

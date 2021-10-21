
#define delaytime 1000
int Buzzer=8;

void setup() {
  // put your setup code here, to run once:
pinMode(Buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
 unsigned char i;

 while(1)
 {
  for(int i=1;i<80;i++){
    digitalWrite(Buzzer,HIGH);
    delay(delaytime-100);
    digitalWrite(Buzzer,LOW);
    delay(delaytime+100);
    }
    for(int i=1;i<100;i++){
    digitalWrite(Buzzer,HIGH);
    delay(delaytime+200);
    digitalWrite(Buzzer,LOW);
    delay(delaytime-200);
    }
  }
}

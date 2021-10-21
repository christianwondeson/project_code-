#include <IRremote.h> 
int IR_pin=11;
int dt=1500;
String command;
IRrecv irRemote(IR_pin); //specifing our pin and using method form library
decode_results result; //storing our value on  result and  decoding when needed 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
irRemote.enableIRIn();  //starting our irremote 
}

void loop() {
  // put your main code here, to run repeatedly:
  while(irRemote.decode(&result)==0){
    
    }// nothing wilk happen if no buton is puhed form the remote
    
    Serial.println(result.value,HEX);  //display our remote initailized hex value
    delay(dt);
    irRemote.resume(); //them free for some second before entering other buttons
}

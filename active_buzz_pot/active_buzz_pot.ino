int pot_value;
int buzzer_pin=7;
int pot_pin=A3;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzzer_pin,OUTPUT);
pinMode(pot_pin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot_value=analogRead(pot_pin);
  Serial.println(pot_value);
  if(pot_value>1000){
    
    digitalWrite(buzzer_pin,HIGH);
    pot_value=analogRead(pot_pin);
    }

    digitalWrite(buzzer_pin,LOW);
}

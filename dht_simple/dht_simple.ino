#include "DHT.h"
#define Sensor_Type DHT11
int pin_type = 2;
float tempC;
float tempF;
float humidity;
DHT HT(pin_type, Sensor_Type);
#define delay_T 500
int delay_loop = 2000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
  delay(delay_T);
}

void loop() {
  // put your main code here, to run repeatedly:
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
  delay(delay_loop);

}

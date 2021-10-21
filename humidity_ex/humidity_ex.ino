#include "DHT.h"
#define DHTPIN 2
#define dhtype DHT11

DHT dht(DHTPIN, dhtype);

void setup() {
  // put your setup code here, to run once:
  //begin serial monitor on 9600 bandwidth or frequency
  Serial.begin(9600);
  dht.begin();
  Serial.println("temp observation !!");

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  double temp_c = dht.readTemperature();
  double temp_f = dht.readTemperature(true);
  double hum_measure = dht.readHumidity();

  if (isnan(temp_c) || isnan(temp_r) || isnan(hum_measure)) {

    Serial.println("ERROR HAS OCCURED !!");
  } else {

    Serial.println("HUMIDITY :");
    Serial.println(hum_measure + "%");
    Serial.println("Temperature in celsius");
    Serial.println(temp_c);
    Serial.println("℃");
    Serial.println("Temperature in farhenit");
    Serial.println(temp_f);
    Serial.println("℉");
    
  }
}

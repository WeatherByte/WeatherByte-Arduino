#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

/*
  Arduino Code: WeatherByte 
  -> http://www.ladyada.net/learn/sensors/dht.html
*/

void setup() {
  Serial.begin(9600);  
  dht.begin();
}

void loop() {
  // Reading temperature or humidity takes 250 milliseconds
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
  }
}

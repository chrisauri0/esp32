#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(9600);
dht.begin();
}
void loop() {

delay(2000);
float h = dht.readHumidity();

float t = dht.readTemperature();  
float f = dht.readTemperature(true);


Serial.print("Humedad: ");
Serial.print(h);
Serial.print("% Temperatura: ");
Serial.print(t);
Serial.print("°C ");
Serial.print(f);
Serial.print("°F");
}

#include <Arduino.h>

#define POT_PIN 35  // Pin donde está conectado el potenciómetro
int LEDpin = 4;  // Pin donde está conectado el LED

void setup() {
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  int adcVal = analogRead(POT_PIN); // Leer el valor del potenciómetro (0 - 4095)
  int brightness = map(adcVal, 0, 4095, 0, 255); // Convertir a rango 0-255
  analogWrite(LEDpin, brightness); // Ajustar brillo del LED
  delay(20);
}

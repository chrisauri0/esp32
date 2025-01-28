
// Definir el pin donde está conectado el LED
#include <Arduino.h>
int LEDpin = 4;  // Puedes cambiar el pin si lo necesitas

void setup() {
  // Configurar el canal PWM
  pinMode(LEDpin, OUTPUT);

}
void loop() {
  for(int dutyCycle = 0;dutyCycle<=255;dutyCycle++){
    analogWrite(LEDpin, dutyCycle);
    delay(20);
  }

}

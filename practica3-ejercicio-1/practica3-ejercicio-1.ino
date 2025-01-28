#include <Arduino.h>
int LEDpin = 4;  // Definir el pin donde está conectado el LED

void setup() {
//configurar como salida el puerto del led
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  //declaramos un ciclo que llegara hasta 255 de valor para el brillo durante 20ms aumenta 
  for(int dutyCycle = 0;dutyCycle<=255;dutyCycle++){
    analogWrite(LEDpin, dutyCycle);
    delay(20);
  }

}

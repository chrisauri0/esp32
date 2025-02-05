#include <Arduino.h>

// Pin del potenciómetro (ADC1)
const int pot_pin = 34;

// Pin de salida PWM para controlar el motor (conectado al gate de un MOSFET o entrada del driver)
const int motor_pin = 5;

// Configuración del PWM para ESP32
const int freq = 5000;     // Frecuencia PWM (puedes ajustar este valor)
const int channel = 0;     // Canal PWM (del 0 al 15)
const int resolution = 8;  // Resolución de 8 bits (valores de 0 a 255)

void setup() {
  Serial.begin(9600);
  
  // Configurar el canal PWM y asignarlo al pin motor_pin
  
}

void loop() {
  // Leer el valor del potenciómetro (0 a 4095)
  int pot_value = analogRead(pot_pin);

  // Mapear el valor leído a un rango PWM (0 a 255)
  int speed = map(pot_value, 0, 4095, 0, 255);
  
  // Enviar el valor PWM para controlar la velocidad del motor
  analogWrite(channel, speed);
  
  // Imprimir el valor para monitoreo
  Serial.print("Pot value: ");
  Serial.print(pot_value);
  Serial.print(" => PWM: ");
  Serial.println(speed);
  
  delay(15); // Pequeño retardo para suavizar la lectura
}

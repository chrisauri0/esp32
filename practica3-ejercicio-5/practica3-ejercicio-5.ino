#include "Servo.h"
#define POT_PIN 35  // Pin donde está conectado el potenciómetro
int servo_pin = 4; // pin 4 para el serve
Servo myservo;
int angle = 0;
void setup()
{
myservo.attach(servo_pin);
}

void loop()
{ // move from 0 to 180 degrees with a positive angle of 1
val = analogRead(potpin);
val = map(val, 0, 1023, 0, 180);
myservo.write(val);
}
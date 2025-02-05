#include <ESP32Servo.h>

// Configuración del servomotor
const int servo_pin = 4;    // Pin del servo
Servo myservo;              // Objeto servo

// Configuración del sensor HC-SR04
const int trigPin = 12;     // Pin TRIG del HC-SR04
const int echoPin = 14;     // Pin ECHO del HC-SR04

long duration;              // Duración del pulso (en microsegundos)
float distance;             // Distancia calculada (en cm)

void setup() {
  Serial.begin(9600);       
  myservo.attach(servo_pin); 

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  
  myservo.write(0);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  
  distance = (duration * 0.0343) / 2;
  
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");
  
 
  if (distance < 5.0) {
  while (distance < 5.0) {
    myservo.write(90);
    
    // Medir de nuevo la distancia dentro del while
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration * 0.0343) / 2;
    
    delay(100);
  }
}
else {
  myservo.write(0);
}

  
  delay(100); 
}

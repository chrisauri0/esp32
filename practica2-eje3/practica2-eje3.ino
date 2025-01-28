int DISTANCIA = 0;
int pinLed = 2;
int pinEco = 12;
int pinGatillo = 13;

long readUltrasonicDistance(int triggerPin, int echoPin) {
    pinMode(triggerPin, OUTPUT);
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    return pulseIn(echoPin, HIGH);
}

void setup() {
    Serial.begin(115200);
    pinMode(pinLed, OUTPUT);
}

void loop() {
    DISTANCIA = 0.01723 * readUltrasonicDistance(pinGatillo, pinEco);
    
    Serial.print("Distancia: ");
    Serial.print(DISTANCIA);
    Serial.println(" cm");

    if (DISTANCIA < 20) {
        digitalWrite(pinLed, HIGH);
    } else {
        digitalWrite(pinLed, LOW);
    }

    delay(500);  // Aumenté el delay a 500ms para que la lectura sea más visible en el monitor serial.
}

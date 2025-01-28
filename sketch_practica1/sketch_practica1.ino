#define ADC_VREF_mV 3300.0 // Voltaje de referencia en milivoltios
#define ADC_RESOLUTION 4096.0 // Resolución del ADC
#define PIN_LM35 36 // ESP32 pin GPIO36 (ADC0) conectado al LM35

void setup() {
    Serial.begin(115200);
    // Configurar la atenuación del ADC a 11 dB (hasta ~3.3V de entrada)
    analogSetAttenuation(ADC_11db);
}

void loop() {
    // Leer el valor ADC desde el sensor LM35
    int adcVal = analogRead(PIN_LM35);

    // Convertir el valor ADC a voltaje en milivoltios
    float milliVolt = adcVal * (ADC_VREF_mV / ADC_RESOLUTION);

    // Convertir el voltaje a temperatura en °C
    float tempC = milliVolt / 10;

    // Convertir °C a °F
    float tempF = tempC * 9 / 5 + 32;

    // Mostrar los resultados en el Monitor Serial
    Serial.print("Voltage: ");
    Serial.print(milliVolt / 1000, 3); // Mostrar voltaje en voltios con 3 decimales
    Serial.print(" V, ");

    Serial.print("Temperature: ");
    Serial.print(tempC); // Temperatura en °C
    Serial.print("°C ~ ");
    Serial.print(tempF); // Temperatura en °F
    Serial.println("°F");

    // Enviar solo el voltaje para el Serial Plotter
    Serial.println(milliVolt / 1000, 3); // Esto permitirá graficar el voltaje en el plotter

    delay(500);
}

#include <DHT.h>
#define POT_PIN 32       // Potentiometer connected to GPIO 32
#define LED_BUILTIN 4    // LED on GPIO 4
#define BUZZER 5         // Buzzer on GPIO 5
#define DHT_PIN 15       // DHT22 data pin
#define DHT_TYPE DHT22   // DHT22 Sensor Type

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    dht.begin();
    Serial.println("ESP32 Fire Alarm System Test");
}

void loop() {
    int sensorValue = analogRead(POT_PIN);
    float temp = map(sensorValue, 0, 4095, 0, 100); // 0-100 limit

    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println("°C");

    if (temp > 50) {  // Fire Condition
        digitalWrite(LED_BUILTIN, HIGH);  // LED ON
        Serial.println("Fire detected, raising alarms.");

        tone(BUZZER, 1000);   // (low pitch)
        delay(500);           // wait
        noTone(BUZZER);       // stop
        delay(200);           // wait
        tone(BUZZER, 2000);   // (high pitch)
        delay(500);           // wait
        noTone(BUZZER);       // stop
        delay(200);           // wait
    } else {
        digitalWrite(LED_BUILTIN, LOW);   // Turn off LED
        noTone(BUZZER);  // No beep sound
        Serial.println("No fire detected.");
    }

    delay(1000);
}

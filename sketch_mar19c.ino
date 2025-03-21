#include <CapacitiveSensor.h>

#define BUZZER 11
#define NUM_KEYS 8

CapacitiveSensor cs[NUM_KEYS] = {
    CapacitiveSensor(10, 2),
    CapacitiveSensor(10, 3),
    CapacitiveSensor(10, 4),
    CapacitiveSensor(10, 5),
    CapacitiveSensor(10, 6),
    CapacitiveSensor(10, 7),
    CapacitiveSensor(10, 8),
    CapacitiveSensor(10, 9)
};

const int notes[NUM_KEYS] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {
    pinMode(BUZZER, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    for (int i = 0; i < NUM_KEYS; i++) {
        long touchValue = cs[i].capacitiveSensor(30);
        Serial.print("Tecla "); Serial.print(i); Serial.print(": ");
        Serial.println(touchValue);

        if (touchValue > 1000) { // Ajuste esse valor conforme necessário
            tone(BUZZER, notes[i]);
            delay(100);
        } else {
            noTone(BUZZER);
        }
    }
}

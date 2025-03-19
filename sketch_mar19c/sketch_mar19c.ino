#include <CapacitiveSensor.h>

#define BUZZER 11
#define NUM_KEYS 8

CapacitiveSensor cs[NUM_KEYS] = {
    CapacitiveSensor(4, 2),
    CapacitiveSensor(4, 3),
    CapacitiveSensor(4, 4),
    CapacitiveSensor(4, 5),
    CapacitiveSensor(4, 6),
    CapacitiveSensor(4, 7),
    CapacitiveSensor(4, 8),
    CapacitiveSensor(4, 9)
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

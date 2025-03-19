#define BUZZER 11
#define NUM_KEYS 8

const int keys[NUM_KEYS] = {2, 3, 4, 5, 6, 7, 8, 9};
const int notes[NUM_KEYS] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {
    pinMode(BUZZER, OUTPUT);
    
    for (int i = 0; i < NUM_KEYS; i++) {
        pinMode(keys[i], INPUT_PULLUP); // Ativa o pull-up interno
    }
}

void loop() {
    bool keyPressed = false;

    for (int i = 0; i < NUM_KEYS; i++) {
        if (digitalRead(keys[i]) == LOW) { // Agora a tecla é ativa em nível baixo
            tone(BUZZER, notes[i]);
            keyPressed = true;
            delay(200); // Pequeno delay para evitar repetições rápidas
        }
    }

    if (!keyPressed) {
        noTone(BUZZER);
    }
}

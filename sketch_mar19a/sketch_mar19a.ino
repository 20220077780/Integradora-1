#define BUZZER 11
#define NUM_KEYS 8
const int keys[NUM_KEYS] = {2, 3, 4, 5, 6, 7, 8, 9};
const int notes[NUM_KEYS] = {262, 294, 330, 349, 392, 440, 494, 523};
void setup() {
pinMode(BUZZER, OUTPUT);
pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT);
pinMode(4, INPUT);
pinMode(5, INPUT);
pinMode(6, INPUT);
pinMode(7, INPUT);
pinMode(8, INPUT);
pinMode(9, INPUT);
}
void loop() {
for (int i = 0; i < NUM_KEYS; i++) {
if (digitalRead(keys[i]) == HIGH) {
tone(BUZZER, notes[i]);
delay(200);
}
}
noTone(BUZZER);
}

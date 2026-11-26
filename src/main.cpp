#include <Arduino.h>

bool led = true;

void setup() {
  pinMode(23, OUTPUT);
  pinMode(22, INPUT_PULLDOWN);
  digitalWrite(23, led);
}

void loop() {
  if (digitalRead(22) == HIGH) {
    delay(50);                          // debounce the press
    led = !led;
    digitalWrite(23, led);
    while (digitalRead(22) == HIGH) {}  // wait until the button is released
    delay(50);                          // debounce the release
  }
}
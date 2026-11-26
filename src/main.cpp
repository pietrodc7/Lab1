#include <Arduino.h> // test

bool led_on = true;               // remembers LED state, starts as on

void setup() {
  pinMode(23, OUTPUT);           // pin 23 = LED
  pinMode(22, INPUT_PULLDOWN);   // pin 22 = button, LOW when released
  digitalWrite(23, HIGH);        // LED on at startup
}

void loop() {
  if (digitalRead(22) == HIGH) { // button pressed
    led_on = !led_on;              // flip the state
    digitalWrite(23, led_on);     // update the LED
    delay(200);                  // debounce
  }
}
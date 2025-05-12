#include "Led.h"

#define LED_PIN 3

Led led(LED_PIN);

void setup() {
  Serial.begin(9600);
  led.begin();
}

void loop() {
  led.update();
}
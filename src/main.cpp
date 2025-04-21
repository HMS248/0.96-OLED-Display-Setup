#include <Arduino.h>
#include "display.h"

void setup() {
  Serial.begin(115200);
  initDisplay();
  
  displayText("Hello ESP32!");
  displayText("OLED Working", 1);
  display.display();
}

void loop() {
  // Your code here
}

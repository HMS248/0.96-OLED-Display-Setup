#include "display.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// SPI Configuration
#define OLED_MOSI   23
#define OLED_CLK    18
#define OLED_DC     2
#define OLED_CS     5
#define OLED_RESET  4

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void initDisplay() {
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void displayText(const char* text, uint8_t line = 0) {
  display.setCursor(0, line * 10);
  display.println(text);
  display.display();
}

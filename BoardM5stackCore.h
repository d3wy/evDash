#pragma once

// Setup for m5stack core
#define USER_SETUP_LOADED 1
#define SPI_FREQUENCY 27000000
#define SPI_TOUCH_FREQUENCY 2500000
#define USER_SETUP_LOADED 1
#define ILI9341_DRIVER
#define M5STACK
#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS 14  // Chip select control pin
#define TFT_DC 27  // Data Command control pin
#define TFT_RST 33 // Reset pin (could connect to Arduino RESET pin)
#define TFT_BL 32  // LED back-light
#define SPI_FREQUENCY 27000000
#define SPI_READ_FREQUENCY 5000000
// BEEP PIN
#define SPEAKER_PIN 25
#define TONE_PIN_CHANNEL 0

// SDCARD
#define SDCARD_CS 4
#define SDCARD_MOSI 23
#define SDCARD_MISO 19
#define SDCARD_SCLK 18

#define BUTTON_LEFT 37
#define BUTTON_MIDDLE 38
#define BUTTON_RIGHT 39

//
#include "BoardInterface.h"
#include "Board320_240.h"
#include <M5Stack.h>

class BoardM5stackCore : public Board320_240
{

protected:
  M5Stack M5core1;
  TFT_eSprite spr = TFT_eSprite(&M5core1.Lcd);

public:
  void initBoard() override;
  void mainLoop() override;
  void initDisplay() override;
  void displayMessage(const char *row1, const char *row2) override;
  int16_t tftHeight(void) override;
  uint8_t tftGetRotation(void) override;
  void tftSetRotation(uint8_t r) override;
  void tftFillScreen(uint32_t color) override;
  void tftFillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color) override;
  void tftSetTextDatum(uint8_t datum) override;
  void tftSetTextColor(uint16_t fgcolor, uint16_t bgcolor) override;
  void tftSetTextSize(uint8_t size) override;
  int16_t tftDrawString(const char *string, int32_t x, int32_t y, uint8_t font) override;
  int16_t tftDrawString(const String &string, int32_t x, int32_t y, uint8_t font) override;
  void tftSetFreeFont(String fontName) override;
  int16_t sprFontHeight(void) override;
  void sprFillSprite(uint32_t color) override;
  void sprFillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color) override;
  void sprFillCircle(int32_t x, int32_t y, int32_t r, uint32_t color) override;
  void sprFillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint32_t color) override;
  void sprDrawLine(int32_t xs, int32_t ys, int32_t xe, int32_t ye, uint32_t color) override;
  void sprDrawFastVLine(int32_t x, int32_t y, int32_t h, uint32_t color) override;
  void sprDrawFastHLine(int32_t x, int32_t y, int32_t w, uint32_t color) override;
  void sprDrawCircle(int32_t x, int32_t y, int32_t r, uint32_t color) override;
  void sprSetTextDatum(uint8_t datum) override;
  void sprSetTextColor(uint16_t fgcolor, uint16_t bgcolor) override;
  void sprSetTextSize(uint8_t size) override;
  int16_t sprDrawString(const char *string, int32_t x, int32_t y, uint8_t font) override;
  int16_t sprDrawString(const String &string, int32_t x, int32_t y, uint8_t font) override;
  void sprSetFreeFont(String fontName) override;
  void displaySprite() override;
};

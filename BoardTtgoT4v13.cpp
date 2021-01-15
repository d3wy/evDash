#include "BoardInterface.h"
#include "Board320_240.h"
#include "BoardTtgoT4v13.h"
#include <TFT_eSPI.h>

/**
  Init board
*/
void BoardTtgoT4v13::initBoard() {

  pinButtonLeft = BUTTON_LEFT;
  pinButtonRight = BUTTON_RIGHT;
  pinButtonMiddle = BUTTON_MIDDLE;
  //pinSpeaker = SPEAKER_PIN;
  pinBrightness = TFT_BL;
  pinSdcardCs = SDCARD_CS;
  pinSdcardMosi = SDCARD_MOSI;
  pinSdcardMiso = SDCARD_MISO;
  pinSdcardSclk = SDCARD_SCLK;

  //
  Board320_240::initBoard();
}

/**
   Init display
*/
void BoardTtgoT4v13::initDisplay() {

  tft.begin();
  tft.invertDisplay(invertDisplay);
  tft.setRotation(liveData->settings.displayRotation);
  setBrightness((liveData->settings.lcdBrightness == 0) ? 100 : liveData->settings.lcdBrightness);
  tft.fillScreen(TFT_BLACK);

  bool psramUsed = false; // 320x240 16bpp sprites requires psram
#if defined (ESP32) && defined (CONFIG_SPIRAM_SUPPORT)
  if (psramFound())
    psramUsed = true;
#endif
  spr.setColorDepth((psramUsed) ? 16 : 8);
  spr.createSprite(320, 240);
}

/**
   Clear screen a display two lines message
   Must draw directly to tft (due to psramFound check)
*/
void BoardTtgoT4v13::displayMessage(const char* row1, const char* row2) {

  tft.fillScreen(TFT_BLACK);
  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setFreeFont(&Roboto_Thin_24);
  tft.setTextDatum(BL_DATUM);
  tft.drawString(row1, 0, 240 / 2, GFXFF);
  tft.drawString(row2, 0, (240 / 2) + 30, GFXFF);
}

/**
  tftHeight
*/
int16_t BoardTtgoT4v13::tftHeight(void) {
  return tft.height();
}

/**
  tftGetRotation
*/
uint8_t BoardTtgoT4v13::tftGetRotation(void) {
  return tft.getRotation();
}

/**
  tftSetRotation
*/
void BoardTtgoT4v13::tftSetRotation(uint8_t r) {
  tft.setRotation(r);
}

/**
  tftFillScreen
*/
void BoardTtgoT4v13::tftFillScreen(uint32_t color) {
  tft.fillScreen(color);
}

/**
  tftFillRect
*/
void BoardTtgoT4v13::tftFillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color) {
  tft.fillRect(x, y, w, h, color);
}

/**
  tftSetTextDatum
*/
void BoardTtgoT4v13::tftSetTextDatum(uint8_t datum) {
  tft.setTextDatum(datum);
}

/**
  tftSetTextColor
*/
void BoardTtgoT4v13::tftSetTextColor(uint16_t fgcolor, uint16_t bgcolor) {
  tft.setTextColor(fgcolor, bgcolor);
}

/**
  tftSetTextSize
*/
void BoardTtgoT4v13::tftSetTextSize(uint8_t size) {
  tft.setTextSize(size);
}

/**
  tftDrawString
*/
int16_t BoardTtgoT4v13::tftDrawString(const char *string, int32_t x, int32_t y, uint8_t font) {
  tft.drawString(string, x, y, font);
}

/**
  tftDrawString
*/
int16_t BoardTtgoT4v13::tftDrawString(const String& string, int32_t x, int32_t y, uint8_t font) {
  tft.drawString(string, x, y, font);
}

/**
  tftSetFreeFont
*/
void BoardTtgoT4v13::tftSetFreeFont(String fontName) {
  if (fontName == "Roboto_Thin_24")
    tft.setFreeFont(&Roboto_Thin_24);
  if (fontName == "Orbitron_Light_24")
    tft.setFreeFont(&Orbitron_Light_24);
  if (fontName == "Orbitron_Light_32")
    tft.setFreeFont(&Orbitron_Light_32);
}

/**
  sprFontHeight
*/
int16_t BoardTtgoT4v13::sprFontHeight(void) {
  return spr.fontHeight();
}

/**
  sprFillSprite
*/
void BoardTtgoT4v13::sprFillSprite(uint32_t color) {
  spr.fillSprite(color);
}

/**
  sprFillRect
*/
void BoardTtgoT4v13::sprFillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color) {
  spr.fillRect(x, y, w, h, color);
}

/**
  sprFillCircle
*/
void BoardTtgoT4v13::sprFillCircle(int32_t x, int32_t y, int32_t r, uint32_t color) {
  spr.fillCircle(x, y, r, color);
}

/**
  sprFillTriangle
*/
void BoardTtgoT4v13::sprFillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint32_t color) {
  spr.fillTriangle(x1, y1, x2, y2, x3, y3, color);
}

/**
  sprDrawLine
*/
void BoardTtgoT4v13::sprDrawLine(int32_t xs, int32_t ys, int32_t xe, int32_t ye, uint32_t color) {
  spr.drawLine(xs, ys, xe, ye, color);
}

/**
  sprDrawFastVLine
*/
void BoardTtgoT4v13::sprDrawFastVLine(int32_t x, int32_t y, int32_t h, uint32_t color) {
  spr.drawFastVLine(x, y, h, color);
}

/**
  sprDrawFastHLine
*/
void BoardTtgoT4v13::sprDrawFastHLine(int32_t x, int32_t y, int32_t w, uint32_t color) {
  spr.drawFastHLine(x, y, w, color);
}

/**
  sprDrawCircle
*/
void BoardTtgoT4v13::sprDrawCircle(int32_t x, int32_t y, int32_t r, uint32_t color) {
  spr.drawCircle(x, y, r, color);
}

/**
  sprSetTextDatum
*/
void BoardTtgoT4v13::sprSetTextDatum(uint8_t datum) {
  spr.setTextDatum(datum);
}

/**
  sprSetTextColor
*/
void BoardTtgoT4v13::sprSetTextColor(uint16_t fgcolor, uint16_t bgcolor) {
  spr.setTextColor(fgcolor, bgcolor);
}

/**
  sprSetTextSize
*/
void BoardTtgoT4v13::sprSetTextSize(uint8_t size) {
  spr.setTextSize(size);
}

/**
  sprDrawString
*/
int16_t BoardTtgoT4v13::sprDrawString(const char *string, int32_t x, int32_t y, uint8_t font) {
  spr.drawString(string, x, y, font);
}

/**
  sprDrawString
*/
int16_t BoardTtgoT4v13::sprDrawString(const String& string, int32_t x, int32_t y, uint8_t font) {
  spr.drawString(string, x, y, font);
}

/**
  sprSetF
*/
void BoardTtgoT4v13::sprSetFreeFont(String fontName) {
  if (fontName == "Roboto_Thin_24")
    spr.setFreeFont(&Roboto_Thin_24);
  if (fontName == "Orbitron_Light_24")
    spr.setFreeFont(&Orbitron_Light_24);
  if (fontName == "Orbitron_Light_32")
    spr.setFreeFont(&Orbitron_Light_32);
}

/**
  displaySprite
*/
void BoardTtgoT4v13::displaySprite() {
  spr.pushSprite(0, 0);
}

#include "BoardInterface.h"
#include "BoardM5stackCore.h"
#include "Board320_240.h"
#include <M5Stack.h>

/**
  Init board
*/
void BoardM5stackCore::initBoard()
{

  invertDisplay = true;

  pinButtonLeft = BUTTON_LEFT;
  pinButtonRight = BUTTON_RIGHT;
  pinButtonMiddle = BUTTON_MIDDLE;
  pinSpeaker = SPEAKER_PIN;
  pinBrightness = TFT_BL;
  pinSdcardCs = SDCARD_CS;
  pinSdcardMosi = SDCARD_MOSI;
  pinSdcardMiso = SDCARD_MISO;
  pinSdcardSclk = SDCARD_SCLK;

  // Mute speaker
  //ledcWriteTone(TONE_PIN_CHANNEL, 0);
  //dacWrite(SPEAKER_PIN, 0);

  //
  Board320_240::initBoard();
}

/**
 * Main loop
 */
void BoardM5stackCore::mainLoop()
{

  M5core1.update();
  Board320_240::mainLoop();
}

/**
 * Init display
 */
void BoardM5stackCore::initDisplay()
{
  // initialize the M5Stack object
  M5core1.begin();
  M5core1.Power.begin();

  // Lcd display
  M5core1.Lcd.fillScreen(WHITE);
  delay(500);
  M5core1.Lcd.fillScreen(RED);
  delay(500);
  M5core1.Lcd.fillScreen(GREEN);
  delay(500);
  M5core1.Lcd.fillScreen(BLUE);
  delay(500);
  M5core1.Lcd.fillScreen(BLACK);
  delay(500);
}

/**
   Clear screen a display two lines message
*/
void BoardM5stackCore::displayMessage(const char *row1, const char *row2)
{

  // Must draw directly, without sprite (due to psramFound check)
  M5core1.Lcd.fillScreen(TFT_BLACK);
  M5core1.Lcd.setTextDatum(ML_DATUM);
  M5core1.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
  M5core1.Lcd.setFreeFont(&Roboto_Thin_24);
  M5core1.Lcd.setTextDatum(BL_DATUM);
  M5core1.Lcd.drawString(row1, 0, 240 / 2, GFXFF);
  M5core1.Lcd.drawString(row2, 0, (240 / 2) + 30, GFXFF);
}

/**
  tftHeight
*/
int16_t BoardM5stackCore::tftHeight(void)
{
  return M5core1.Lcd.height();
}

/**
  tftGetRotation
*/
uint8_t BoardM5stackCore::tftGetRotation(void)
{
  return M5core1.Lcd.getRotation();
}

/**
  tftSetRotation
*/
void BoardM5stackCore::tftSetRotation(uint8_t r)
{
  M5core1.Lcd.setRotation(r);
}

/**
  tftFillScreen
*/
void BoardM5stackCore::tftFillScreen(uint32_t color)
{
  M5core1.Lcd.fillScreen(color);
}

/**
  tftFillRect
*/
void BoardM5stackCore::tftFillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color)
{
  M5core1.Lcd.fillRect(x, y, w, h, color);
}

/**
  tftSetTextDatum
*/
void BoardM5stackCore::tftSetTextDatum(uint8_t datum)
{
  M5core1.Lcd.setTextDatum(datum);
}

/**
  tftSetTextColor
*/
void BoardM5stackCore::tftSetTextColor(uint16_t fgcolor, uint16_t bgcolor)
{
  M5core1.Lcd.setTextColor(fgcolor, bgcolor);
}

/**
  tftSetTextSize
*/
void BoardM5stackCore::tftSetTextSize(uint8_t size)
{
  M5core1.Lcd.setTextSize(size);
}

/**
  tftDrawString
*/
int16_t BoardM5stackCore::tftDrawString(const char *string, int32_t x, int32_t y, uint8_t font)
{
  M5core1.Lcd.drawString(string, x, y, font);
}

/**
  tftDrawString
*/
int16_t BoardM5stackCore::tftDrawString(const String &string, int32_t x, int32_t y, uint8_t font)
{
  M5core1.Lcd.drawString(string, x, y, font);
}

/**
  tftSetFreeFont
*/
void BoardM5stackCore::tftSetFreeFont(String fontName)
{
  if (fontName == "Roboto_Thin_24")
    M5core1.Lcd.setFreeFont(&Roboto_Thin_24);
  if (fontName == "Orbitron_Light_24")
    M5core1.Lcd.setFreeFont(&Orbitron_Light_24);
  if (fontName == "Orbitron_Light_32")
    M5core1.Lcd.setFreeFont(&Orbitron_Light_32);
}

/**
  sprFontHeight
*/
int16_t BoardM5stackCore::sprFontHeight(void)
{
  return spr.fontHeight();
}

/**
  sprFillSprite
*/
void BoardM5stackCore::sprFillSprite(uint32_t color)
{
  spr.fillSprite(color);
}

/**
  sprFillRect
*/
void BoardM5stackCore::sprFillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color)
{
  spr.fillRect(x, y, w, h, color);
}

/**
  sprFillCircle
*/
void BoardM5stackCore::sprFillCircle(int32_t x, int32_t y, int32_t r, uint32_t color)
{
  spr.fillCircle(x, y, r, color);
}

/**
  sprFillTriangle
*/
void BoardM5stackCore::sprFillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint32_t color)
{
  spr.fillTriangle(x1, y1, x2, y2, x3, y3, color);
}

/**
  sprDrawLine
*/
void BoardM5stackCore::sprDrawLine(int32_t xs, int32_t ys, int32_t xe, int32_t ye, uint32_t color)
{
  spr.drawLine(xs, ys, xe, ye, color);
}

/**
  sprDrawFastVLine
*/
void BoardM5stackCore::sprDrawFastVLine(int32_t x, int32_t y, int32_t h, uint32_t color)
{
  spr.drawFastVLine(x, y, h, color);
}

/**
  sprDrawFastHLine
*/
void BoardM5stackCore::sprDrawFastHLine(int32_t x, int32_t y, int32_t w, uint32_t color)
{
  spr.drawFastHLine(x, y, w, color);
}

/**
  sprDrawCircle
*/
void BoardM5stackCore::sprDrawCircle(int32_t x, int32_t y, int32_t r, uint32_t color)
{
  spr.drawCircle(x, y, r, color);
}

/**
  sprSetTextDatum
*/
void BoardM5stackCore::sprSetTextDatum(uint8_t datum)
{
  spr.setTextDatum(datum);
}

/**
  sprSetTextColor
*/
void BoardM5stackCore::sprSetTextColor(uint16_t fgcolor, uint16_t bgcolor)
{
  spr.setTextColor(fgcolor, bgcolor);
}

/**
  sprSetTextSize
*/
void BoardM5stackCore::sprSetTextSize(uint8_t size)
{
  spr.setTextSize(size);
}

/**
  sprDrawString
*/
int16_t BoardM5stackCore::sprDrawString(const char *string, int32_t x, int32_t y, uint8_t font)
{
  spr.drawString(string, x, y, font);
}

/**
  sprDrawString
*/
int16_t BoardM5stackCore::sprDrawString(const String &string, int32_t x, int32_t y, uint8_t font)
{
  spr.drawString(string, x, y, font);
}

/**
  sprSetF
*/
void BoardM5stackCore::sprSetFreeFont(String fontName)
{
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
void BoardM5stackCore::displaySprite()
{
  spr.pushSprite(0, 0);
}

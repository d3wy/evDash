#ifndef BOARDTTGOT4V13_H
#define BOARDTTGOT4V13_H

// Setup for TTGO T4 v13
#define USER_SETUP_LOADED 1
#define SPI_FREQUENCY  27000000
#define SPI_TOUCH_FREQUENCY  2500000

#define ILI9341_DRIVER
#define TFT_MISO 12
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS   27
#define TFT_DC   32
#define TFT_RST   5
//#define TFT_BACKLIGHT_ON HIGH
#define TFT_BL 4

#define USE_HSPI_PORT
//#define SPI_FREQUENCY  40000000   // Maximum for ILI9341
#define SPI_READ_FREQUENCY  6000000 // 6 MHz is the maximum SPI read speed for the ST7789V

#define SDCARD_CS    13
#define SDCARD_MOSI  15
#define SDCARD_MISO  2
#define SDCARD_SCLK  14

#define BUTTON_LEFT 38
#define BUTTON_MIDDLE 37
#define BUTTON_RIGHT 39

//
#include "BoardInterface.h"
#include "Board320_240.h"
#include <TFT_eSPI.h>

//
class BoardTtgoT4v13 : public Board320_240 {
  
  protected:   
    // TFT, SD SPI
    TFT_eSPI tft = TFT_eSPI();
    TFT_eSprite spr = TFT_eSprite(&tft);
  public:
    void initBoard() override;
    void initDisplay() override;
    void displayMessage(const char* row1, const char* row2) override;
    int16_t tftHeight(void) override;
    uint8_t tftGetRotation(void) override;
    void tftSetRotation(uint8_t r) override;
    void tftFillScreen(uint32_t color) override;
    void tftFillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color) override;
    void tftSetTextDatum(uint8_t datum) override; 
    void tftSetTextColor(uint16_t fgcolor, uint16_t bgcolor) override;
    void tftSetTextSize(uint8_t size) override;
    int16_t tftDrawString(const char *string, int32_t x, int32_t y, uint8_t font) override;
    int16_t tftDrawString(const String& string, int32_t x, int32_t y, uint8_t font) override;
    void tftSetFreeFont(const GFXfont *f = NULL) override;
    int16_t sprFontHeight(void) override;
    void sprFillSprite(uint32_t color) override;
    void sprFillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color) override;
    void sprFillCircle(int32_t x, int32_t y, int32_t r, uint32_t color) override;
    void sprFillTriangle(int32_t x1,int32_t y1, int32_t x2,int32_t y2, int32_t x3,int32_t y3, uint32_t color) override;
    void sprDrawLine(int32_t xs, int32_t ys, int32_t xe, int32_t ye, uint32_t color) override;
    void sprDrawFastVLine(int32_t x, int32_t y, int32_t h, uint32_t color) override;
    void sprDrawFastHLine(int32_t x, int32_t y, int32_t w, uint32_t color) override;
    void sprDrawCircle(int32_t x, int32_t y, int32_t r, uint32_t color) override;
    void sprSetTextDatum(uint8_t datum) override; 
    void sprSetTextColor(uint16_t fgcolor, uint16_t bgcolor) override;
    void sprSetTextSize(uint8_t size) override;
    int16_t sprDrawString(const char *string, int32_t x, int32_t y, uint8_t font) override;
    int16_t sprDrawString(const String& string, int32_t x, int32_t y, uint8_t font) override;
    void sprSetFreeFont(const GFXfont *f = NULL) override;
    void displaySprite() override;
};

#endif // BOARDTTGOT4V13_H

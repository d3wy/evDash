#pragma once

#include <FS.h>
#include "LiveData.h"
#include "CarInterface.h"
#include "CommInterface.h"

class BoardInterface {

  protected:
    LiveData* liveData;
    CarInterface* carInterface;
    CommInterface* commInterface;
  public:
    // Screens, buttons
    byte displayScreenCount = 7;
    bool btnLeftPressed   = true;
    bool btnMiddlePressed = true;
    bool btnRightPressed  = true;
    bool testDataMode = false;
    bool scanDevices = false;
    String sdcardRecordBuffer = "";
    //
    void setLiveData(LiveData* pLiveData);
    void attachCar(CarInterface* pCarInterface);
    virtual void initBoard() = 0;
    virtual void afterSetup() = 0;
    virtual void mainLoop() = 0;
    virtual bool skipAdapterScan() {
      return false;
    };
    bool carCommandAllowed() {
      return carInterface->commandAllowed();
    }
    void parseRowMerged();
    // Graphics & GUI
    virtual void initDisplay() = 0;
    virtual void displayMessage(const char* row1, const char* row2) = 0;
    virtual void setBrightness(byte lcdBrightnessPerc) = 0;
    virtual void redrawScreen() = 0;
    virtual int16_t tftHeight(void) = 0;
    virtual uint8_t tftGetRotation(void) = 0;
    virtual void tftSetRotation(uint8_t r) = 0;
    virtual void tftFillScreen(uint32_t color) = 0;
    virtual void tftFillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color) = 0;
    virtual void tftSetTextDatum(uint8_t datum) = 0;
    virtual void tftSetTextColor(uint16_t fgcolor, uint16_t bgcolor) = 0;
    virtual void tftSetTextSize(uint8_t size) = 0;
    virtual int16_t tftDrawString(const char *string, int32_t x, int32_t y, uint8_t font) = 0;
    virtual int16_t tftDrawString(const String& string, int32_t x, int32_t y, uint8_t font) = 0;
    virtual void tftSetFreeFont(String fontName) = 0;
    virtual int16_t sprFontHeight(void) = 0;
    virtual void sprFillSprite(uint32_t color) = 0;
    virtual void sprFillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color) = 0;
    virtual void sprFillCircle(int32_t x, int32_t y, int32_t r, uint32_t color) = 0;
    virtual void sprFillTriangle(int32_t x1,int32_t y1, int32_t x2,int32_t y2, int32_t x3,int32_t y3, uint32_t color) = 0;
    virtual void sprDrawLine(int32_t xs, int32_t ys, int32_t xe, int32_t ye, uint32_t color) = 0;
    virtual void sprDrawFastVLine(int32_t x, int32_t y, int32_t h, uint32_t color) = 0;
    virtual void sprDrawFastHLine(int32_t x, int32_t y, int32_t w, uint32_t color) = 0;
    virtual void sprDrawCircle(int32_t x, int32_t y, int32_t r, uint32_t color) = 0;
    virtual void sprSetTextDatum(uint8_t datum) = 0;
    virtual void sprSetTextColor(uint16_t fgcolor, uint16_t bgcolor) = 0;
    virtual void sprSetTextSize(uint8_t size) = 0;
    virtual int16_t sprDrawString(const char *string, int32_t x, int32_t y, uint8_t font) = 0;
    virtual int16_t sprDrawString(const String& string, int32_t x, int32_t y, uint8_t font) = 0;
    virtual void sprSetFreeFont(String fontName) = 0;
    virtual void displaySprite() = 0;
    // Menu
    virtual void showMenu() = 0;
    virtual void hideMenu() = 0;
    // Common
    void shutdownDevice();
    void saveSettings();
    void resetSettings();
    void loadSettings();
    void customConsoleCommand(String cmd);
    // Sdcard
    virtual bool sdcardMount() {
      return false;
    };
    virtual void sdcardToggleRecording() = 0;
    bool serializeParamsToJson(File file, bool inclApiKey = false);
};

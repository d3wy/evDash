#include "BoardInterface.h"
#include "BoardM5stackCore2.h"
#include "Board320_240.h"
#include <M5Core2.h>

/**
  Init board
*/
void BoardM5stackCore2::initBoard() {

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
  dacWrite(SPEAKER_PIN, 0);

  //
  Board320_240::initBoard();
}

/**
 * mainLoop
 */
void BoardM5stackCore2::mainLoop() {

  Board320_240::mainLoop();
}

/**
 * Init display
 */
void BoardM5stackCore2::initDisplay() {
  
  // initialize the M5Stack object
  M5.begin();
}

/**
   Clear screen a display two lines message
*/
void BoardM5stackCore2::displayMessage(const char* row1, const char* row2) {

  // Must draw directly, without sprite (due to psramFound check)
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextDatum(ML_DATUM);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
  M5.Lcd.setFreeFont(&Roboto_Thin_24);
  M5.Lcd.setTextDatum(BL_DATUM);
  M5.Lcd.drawString(row1, 0, 240 / 2, GFXFF);
  M5.Lcd.drawString(row2, 0, (240 / 2) + 30, GFXFF);
}

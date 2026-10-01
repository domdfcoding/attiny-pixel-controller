/*
Fill the LED strip with one colour, then the next
*/

#include <Arduino.h>
#include "common.h"


uint32_t wipe_colours [] = { RED,YELLOW,GREEN,CYAN,BLUE,PURPLE } ; 


/// @brief Fill the LED strip with one colour, then the next
void colour_wipe_nb() { // modified from Adafruit example to make it a state machine
	if (enabled) {
		leds.setBrightness(BRIGHTNESS);
	}

  static int i =0;
  static int col_idx =0;
    leds.setPixelColor(i, wipe_colours[col_idx]);
    leds.show();
  i++;
  if(i >= leds.numPixels()){
    i = 0;
    col_idx++;
    // leds.fill(0); // blank out strip
  }
  if (col_idx > 5) {
    col_idx = 0;
  };
  lastUpdate = millis(); // time for next change to the display
}



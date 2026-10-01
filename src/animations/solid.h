/*
Solid colours
*/

#include <Arduino.h>
#include "common.h"



/// @brief Fill the whole LED strip with one colour
void solid_colour(uint32_t colour, uint8_t brightness) {
	if (enabled) leds.setBrightness(brightness);

  leds.fill(colour);
  leds.show();
  lastUpdate = millis(); // time for next change to the display
}


/// @brief All LEDs off
void off() {
  leds.fill(0);
  leds.show();
  lastUpdate = millis(); // time for next change to the display
}


/*
Demonstation with full-strip colour cycle, and colour cycle along the strip
*/

#define NUMLEDS 3
#define BRIGHTNESS 255
#define NUM_PATTERNS 1
#define PUMPKIN_COLOUR 0x80702000
#define SKULL_COLOUR 0xff800000
#include "common.h"

unsigned long intervals [] = { 40 } ; // speed for each pattern

void updatePattern(uint8_t pat) { // call the pattern currently being created
	switch (pat) {
	case 0:
		if (enabled) leds.setBrightness(BRIGHTNESS);

		leds.setPixelColor(0, PUMPKIN_COLOUR);
		leds.setPixelColor(1, PUMPKIN_COLOUR);
		leds.setPixelColor(2, SKULL_COLOUR);
		leds.show();
		lastUpdate = millis(); // time for next change to the display
		break;
	}
}

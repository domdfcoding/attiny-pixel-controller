/*
Demonstation with full-strip colour cycle, and colour cycle along the strip
*/

#define NUMLEDS 15 // 12 + 3 fake ones for timing
#define BRIGHTNESS 200
#define NUM_PATTERNS 4

#include "animations/colour_wipe.h"
#include "animations/rainbow.h"

unsigned long intervals[] = {20, 100, 10, 100}; // speed for each pattern

/// @brief All LEDs off
void off() {
	leds.fill(0);
	leds.show();
	lastUpdate = millis(); // time for next change to the display
}

void updatePattern(uint8_t pat) { // call the pattern currently being created
	switch (pat) {
	case 0:
		rainbow_single_nb();
		// rainbow_nb();
		break;
	case 1:
		colour_wipe_nb();
		break;
	case 2:
		rainbow_along_alternate_nb();
		break;
	case 3:
		off();
		break;
	}
}

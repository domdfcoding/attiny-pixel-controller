/*
Demonstation with full-strip colour cycle, and colour cycle along the strip
*/

#define NUMLEDS 25
#define BRIGHTNESS 255
#define NUM_PATTERNS 2

#include "animations/colour_wipe.h"
#include "animations/rainbow.h"

unsigned long intervals[] = {40, 100}; // speed for each pattern

void updatePattern(uint8_t pat) { // call the pattern currently being created
	switch (pat) {
	case 0:
		rainbow_nb();
		break;
	case 1:
		colour_wipe_nb();
		break;
	}
}

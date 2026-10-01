/*
Demonstation with full-strip colour cycle, and colour cycle along the strip
*/

#define NUMLEDS 100
#define BRIGHTNESS 100
// #define BRIGHTNESS 0
#define NUM_PATTERNS 2

#include "animations/colour_wipe.h"
#include "animations/rainbow.h"

unsigned long intervals[] = {20, 50}; // speed for each pattern

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

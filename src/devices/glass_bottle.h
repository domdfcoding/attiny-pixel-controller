/*
/*
Demonstation with full-strip colour cycle, and colour cycle along the strip
*/

#define NUMLEDS 25  // 22 + 3 fake ones for timing
#define BRIGHTNESS 50
#define NUM_PATTERNS 4

#include "animations/rainbow.h"
#include "animations/colour_wipe.h"

unsigned long intervals [] = { 120, 20, 2, 80} ; // speed for each pattern

void updatePattern(uint8_t pat) { // call the pattern currently being created
	switch (pat) {
	case 0:
		colour_wipe_nb();
		break;
	case 1:
		rainbow_nb();
		break;
	case 2:
		rainbow_along_nb();
		break;
	case 3:
		rainbow_single_nb();
		break;
	}
}

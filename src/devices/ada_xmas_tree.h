/*
Demonstation with full-strip colour cycle, and colour cycle along the strip
*/

#define NUMLEDS 12
#define BRIGHTNESS 100
#define NUM_PATTERNS 2

#include "animations/rainbow.h"
#include "animations/colour_wipe.h"

unsigned long intervals [] = { 20, 10, } ; // speed for each pattern

void updatePattern(uint8_t pat) { // call the pattern currently being created
	switch (pat) {
	case 0:
		rainbow_nb();
		break;
	case 1:
		rainbow_along_alternate_nb();
		break;
	}
}

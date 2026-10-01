/*
Demonstation with full-strip colour cycle, and colour cycle along the strip
*/

#define NUMLEDS 1
#define BRIGHTNESS 255
#define NUM_PATTERNS 1

#include "animations/pulsate.h"
#include "animations/solid.h"

unsigned long intervals[] = {40}; // speed for each pattern

void updatePattern(uint8_t pat) { // call the pattern currently being created
	switch (pat) {
	case 0:
		// solid_colour(0xFFEA00, BRIGHTNESS);
		// solid_colour(0xffffea00, BRIGHTNESS);
		pulsate_nb(0xffffea00, 1);
		break;
	}
}

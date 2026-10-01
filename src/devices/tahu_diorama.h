/*
Demonstation with full-strip colour cycle, and colour cycle along the strip
*/

#define NUMLEDS 25
#define BRIGHTNESS 64
#define NUM_PATTERNS 4

#include "animations/pulsate.h"
#include "animations/solid.h"

unsigned long intervals[] = {100, 100, 100, 40}; // speed for each pattern

void updatePattern(uint8_t pat) { // call the pattern currently being created
	switch (pat) {
	case 0:
		solid_colour(0xff5e03, BRIGHTNESS);
		break;
	case 1:
		solid_colour(0xff0000, BRIGHTNESS);
		break;
	case 2:
		solid_colour(0xffffff, BRIGHTNESS);
		break;
	case 3:
		pulsate_nb(0xff5e03, 1);
		break;
	}
}

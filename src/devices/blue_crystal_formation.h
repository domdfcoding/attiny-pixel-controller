/*
Crystal formation with blue flicker or colour cycle animations
*/

#define NUMLEDS 1
#define BRIGHTNESS 255
#define NUM_PATTERNS 2

#include "animations/pulsate.h"
#include "animations/rainbow.h"

unsigned long intervals[] = {10, 30};		  // speed for each pattern

void updatePattern(uint8_t pat) { // call the pattern currently being created
	switch (pat) {
	case 0:
		pulsate_nb(BLUE, 1);
		break;
	case 1:
		rainbow_nb();
		break;
	}
}

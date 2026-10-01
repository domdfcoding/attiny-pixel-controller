/*
3D Printed Easter egg lamp with 7-led "star"/"jewel" PCB.
*/

#define NUMLEDS 50  // 7 Actual leds, rest for timing
#define BRIGHTNESS 200
#define NUM_PATTERNS 1

#include "animations/rainbow.h"

unsigned long intervals [] = { 35 } ; // speed for each pattern

void updatePattern(uint8_t pat) {
	switch (pat) {
	case 0:
		rainbow_single_nb();
		break;
	}
}

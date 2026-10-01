/*
3D Printed Crystal formation with "star" PCB
*/

#define NUMLEDS 7
#define BRIGHTNESS 220
#define NUM_PATTERNS 1

#include "animations/rainbow.h"

unsigned long intervals[] = {20}; // speed for each pattern

void updatePattern(uint8_t pat) {
	switch (pat) {
	case 0:
		rainbow_along_nb();
		break;
	}
}

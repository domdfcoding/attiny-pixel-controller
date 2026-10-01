/*
Crystal formation with blue flicker or colour cycle animations
*/

#define NUMLEDS 24
#define BRIGHTNESS 100
#define NUM_PATTERNS 4

#include "animations/pulsate.h"

// // Override default settings
// #define MAX_BRIGHTNESS BRIGHTNESS
// // #define MIN_BRIGHTNESS (MAX_BRIGHTNESS / 3) * 2
// #define MIN_BRIGHTNESS BRIGHTNESS - 30

unsigned long intervals[] = {30, 30, 30, 30};  // speed for each pattern

uint32_t PALE_BLUE = leds.Color(0, 255, 200, 0);
uint32_t WARM_WHITE = leds.Color(255, 224, 160, 0);
uint32_t PALE_GREEN = leds.Color(8, 255, 0, 0);

void updatePattern(uint8_t pat) { // call the pattern currently being created
	switch (pat) {
	case 0:
		pulsate_nb(PALE_BLUE, 1);
		break;
	case 1:
		pulsate_nb(PALE_GREEN, 1);
		break;
	case 2:
		pulsate_nb(BLUE, 1);
		break;
	case 3:
		pulsate_nb(WARM_WHITE, 1);
		break;
	}
}

/*
Demonstation with full-strip colour cycle, and colour cycle along the strip
*/

#define NUMLEDS 50
// #define BRIGHTNESS 80
#define BRIGHTNESS 40
#define NUM_PATTERNS 1

#include "animations/rainbow.h"
#include "animations/colour_wipe.h"

unsigned long intervals [] = { 20, } ; // speed for each pattern

void updatePattern(uint8_t pat) { // call the pattern currently being created
	rainbow_nb();
}

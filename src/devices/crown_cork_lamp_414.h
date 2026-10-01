/*
Demonstation with full-strip colour cycle, and colour cycle along the strip
*/

#define BRIGHTNESS (int)255 * 0.8
#define NUM_PATTERNS 3
// rainbow_along_nb_2 10
// fade_along_nb_2 50
// fade_diagonal_nb 50
// fade_chevron_nb 50
// unsigned long intervals [NUM_PATTERNS] = { 10, 50 } ; // speed for each pattern
unsigned long intervals[NUM_PATTERNS] = {10, 50, 50}; // speed for each pattern

#include "common.h"
#include "devices/crown_cork_lamp_base.h"

void updatePattern(uint8_t pat) { // call the pattern currently being created
	switch (pat) {
	case 0:
		rainbow_along_nb_2(true);
		break;
	case 1:
		// 	// colour_wipe_nb();
		// 	fade_along_nb_2(true);
		// 	break;
		// case 2:
		fade_diagonal_nb(3);
	case 2:
		fade_chevron_nb(5);
		break;
	}
}

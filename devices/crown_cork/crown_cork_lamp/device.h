/*
Demonstation with full-strip colour cycle, and colour cycle along the strip
*/

#define BRIGHTNESS (int)255 * 0.8
#define NUM_PATTERNS 14
// rainbow_along_nb_2 10
// fade_along_nb_2 50
// fade_diagonal_nb 50
// fade_chevron_nb 50

// speed for each pattern
// unsigned long intervals[NUM_PATTERNS] = {10, 50};
unsigned long intervals[NUM_PATTERNS] = {10, 50, 50, 10, 50, 50, 50, 30, 100, 100, 30, 100, 100, 100};

#include "crown_cork_lamp_base.h"
#include "common.h"

uint32_t wipe_colours[] = {RED, YELLOW, GREEN, CYAN, BLUE, PURPLE};

/// @brief fade up to one colour, then down and back up to another
void breathe() { // modified from Adafruit example to make it a state machine

	static int brightness_multiplier = 100;
	static int fade_direction = -1;

	if (enabled) {
		leds.setBrightness(BRIGHTNESS * brightness_multiplier / 100);
	}

	static int col_idx = 0;
	for (int i = 0; i < leds.numPixels(); i++) {
		leds.setPixelColor(i, wipe_colours[col_idx]);
	}
	leds.show();

	brightness_multiplier += fade_direction;

	if (brightness_multiplier == 100) {
		fade_direction = -1;
	} else if (brightness_multiplier == 0) {
		fade_direction = 1;
		col_idx++;
	}

	// leds.fill(0); // blank out strip
	if (col_idx > 5) {
		col_idx = 0;
	};
	lastUpdate = millis(); // time for next change to the display
}

void updatePattern(uint8_t pat) { // call the pattern currently being created
	switch (pat) {

	case 0:
		rainbow_along_nb_2();
		break;
	case 1:
		// colour_wipe_nb();
		fade_along_nb_2(true);
		break;
	case 2:
		fade_diagonal_nb(3, true);
		break;

	// The first three again flipped
	case 3:
		rainbow_along_nb_2(true);
		break;
	case 4:
		// colour_wipe_nb();
		fade_along_nb_2(false);
		break;
	case 5:
		fade_diagonal_nb(3);
		break;

	case 6:
		breathe();
		break;

	case 7:
		rainbow_along_nb_2();
		break;
	case 8:
		// colour_wipe_nb();
		fade_along_nb_2(true);
		break;
	case 9:
		fade_diagonal_nb(3, true);
		break;

	// The first three again flipped
	case 10:
		rainbow_along_nb_2(true);
		break;
	case 11:
		// colour_wipe_nb();
		fade_along_nb_2(false);
		break;
	case 12:
		fade_diagonal_nb(3);
		break;

	case 13:
		breathe();
		break;

	// case 3:
	// 	fade_chevron_nb(5);
	// 	break;
	}
}
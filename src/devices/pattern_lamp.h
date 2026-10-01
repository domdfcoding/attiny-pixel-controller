/*
Lamp from The Range with a nice pattern
*/

#define NUMLEDS 17  // 12 + 5 fake ones for timing
#define BRIGHTNESS 200
#define NUM_PATTERNS 10
// #define NUM_PATTERNS 16

#include "animations/rainbow.h"
#include "animations/colour_wipe.h"
#include "animations/solid.h"

unsigned long intervals [] = { 30, 110, 50, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100} ; // speed for each pattern


// /// @brief Fill the LED strip with one colour, then the next
// void colour_wipe_nb_alt() { // modified from Adafruit example to make it a state machine
// 	if (enabled) {
// 		leds.setBrightness(BRIGHTNESS);
// 	}

//   static int i =0;
//   static uint16_t j = 0;

//   static int col_idx =0;
//     leds.setPixelColor(i, colorwheel(j & 255));
//     leds.show();
//   i++;
//   if(i >= leds.numPixels()){
//     i = 0;
//     j = j + 10;
//     // leds.fill(0); // blank out strip
//   }
//   if (j >= 256)
// 		j = 0;
//   lastUpdate = millis(); // time for next change to the display
// }


/// @brief Fill the LED strip with one colour, then the next, with a delay between colours
void colour_wipe_delay() { // modified from Adafruit example to make it a state machine
	if (enabled) {
		leds.setBrightness(BRIGHTNESS);
	}

  static int i =0;
  static int col_idx =0;
    leds.setPixelColor(i, wipe_colours[col_idx]);
    leds.show();


  i++;
  if(i >= (leds.numPixels() + 50)){
    i = 0;
	col_idx++;
   
    // leds.fill(0); // blank out strip
  }
  if (col_idx > 5) {
    col_idx = 0;
  };
  lastUpdate = millis(); // time for next change to the display
}



/// @brief fade up to one colour, then down and back up to another
void breathe() { // modified from Adafruit example to make it a state machine

	static int brightness_multiplier = 100;
	static int fade_direction = -1;

	if (enabled) {
		leds.setBrightness(BRIGHTNESS * brightness_multiplier / 100);
	}

  static int col_idx =0;
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
		rainbow_single_nb();
		break;
	// case 1:
	// 	// rainbow_along_nb();
	// 	// rainbow_along_nb();
	// 	colour_wipe_nb_alt();
	// 	break;
	case 1:
		colour_wipe_delay();
		break;
	case 2:
		breathe();
		break;
	case 3:
		solid_colour(RED, BRIGHTNESS);
		break;
	case 4:
		solid_colour(YELLOW, BRIGHTNESS);
		break;
	case 5:
		solid_colour(GREEN, BRIGHTNESS);
		break;
	case 6:
		solid_colour(CYAN, BRIGHTNESS);
		break;
	case 7:
		solid_colour(BLUE, BRIGHTNESS);
		break;
	case 8:
		solid_colour(PURPLE, BRIGHTNESS);
		break;
	case 9:
		off();
		break;
	// case 9:
	// 	solid_colour(RED, BRIGHTNESS/2);
	// 	break;
	// case 10:
	// 	solid_colour(YELLOW, BRIGHTNESS/2);
	// 	break;
	// case 11:
	// 	solid_colour(GREEN, BRIGHTNESS/2);
	// 	break;
	// case 12:
	// 	solid_colour(CYAN, BRIGHTNESS/2);
	// 	break;
	// case 13:
	// 	solid_colour(BLUE, BRIGHTNESS/2);
	// 	break;
	// case 14:
	// 	solid_colour(PURPLE, BRIGHTNESS/2);
	// 	break;
	// case 15:
	// 	off();
	// 	break;
	}
}

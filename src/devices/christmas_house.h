/*
3D printed Christmas "snowglobe" with house and 5mm Through Hole WS2812
*/

#define NUMLEDS 1
#define BRIGHTNESS 255
#define MIN_BRIGHTNESS MAX_BRIGHTNESS / 4
#define NUM_PATTERNS 2

#include "animations/pulsate.h"

unsigned long intervals[] = {10};		  // speed for each pattern

// uint32_t CANDLE = leds.Color(255, 160, 0, 0);
// uint32_t CANDLE = leds.Color(235, 152, 52, 0);
uint32_t CANDLE = leds.Color(235, 50, 0, 0);


void updatePattern(uint8_t pat) { // call the pattern currently being created
	switch (pat) {
	case 0:
		pulsate_nb(CANDLE, 1);
		break;
	}
	// TODO: fade between red and green
}

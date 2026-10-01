/*
All LEDs fade through the colours of the rainbow
*/

#include "common.h"
#include <Arduino.h>

/// @brief Cycle all LEDs in the strip through the rainbow
void rainbow_nb() { // modified from Adafruit example to make it a state machine
	if (enabled) {
		leds.setBrightness(BRIGHTNESS);
	}

	static uint16_t j = 0;

	for (int i = 0; i < leds.numPixels(); i++) {
		leds.setPixelColor(i, colorwheel((i + j) & 255));
	}
	leds.show();
	j++;
	if (j >= 256)
		j = 0;
	lastUpdate = millis(); // time for next change to the display
}

/// @brief Cycle all LEDs in the strip through the rainbow, with all LEDs the same colour
void rainbow_single_nb() { // modified from Adafruit example to make it a state machine
	if (enabled) {
		leds.setBrightness(BRIGHTNESS);
	}

	static uint16_t j = 0;
	for (int i = 0; i < leds.numPixels(); i++) {
		leds.setPixelColor(i, colorwheel(j & 255));
	}
	leds.show();
	j++;
	if (j >= 256)
		j = 0;
	lastUpdate = millis(); // time for next change to the display
}

void rainbow_along_nb() { // modified from Adafruit example to make it a state machine
	if (enabled) {
		leds.setBrightness(BRIGHTNESS);
	}

	static uint16_t j = 0;
	static uint16_t i = 0;
	// for (int i = 0; i < leds.numPixels(); i++) {
	uint16_t rc_index = (i * 256 / leds.numPixels()) + j;
	leds.setPixelColor(i, colorwheel(rc_index & 255));
	// }
	leds.show();
	i++;

	if (i >= leds.numPixels()) {
		i = 0;
		j++;
	}

	if (j >= 256) {
		j = 0;
	}
	lastUpdate = millis(); // time for next change to the display
}

void rainbow_along_alternate_nb() { // modified from Adafruit example to make it a state machine
	if (enabled) {
		leds.setBrightness(BRIGHTNESS);
	}

	static uint16_t j = 0;
	static uint16_t i = 0;
	// for (int i = 0; i < leds.numPixels(); i++) {
	uint16_t rc_index = (i * 256 / leds.numPixels()) + j;
	uint16_t led_idx;

	if (i % 2) {
		// Odd
		// led_idx = 12 - i;
		// leds.setPixelColor(12-i, colorwheel(rc_index & 255));
		leds.setPixelColor(i, 0);
	} else {
		leds.setPixelColor(i, colorwheel(rc_index & 255));
	}

	// leds.setPixelColor(led_idx, colorwheel(rc_index & 255));
	// }
	leds.show();
	i++;

	if (i >= leds.numPixels()) {
		i = 0;
		j++;
	}

	if (j >= 256) {
		j = 0;
	}
	lastUpdate = millis(); // time for next change to the display
}



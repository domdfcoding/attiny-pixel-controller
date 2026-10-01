/*
All LEDs slowly fade/flicker between different brightnesses, lit up blue
*/

#include <Arduino.h>
#include "common.h"

// Max/min brightness for plusation animation
#define MAX_BRIGHTNESS BRIGHTNESS

#ifndef MIN_BRIGHTNESS
#define MIN_BRIGHTNESS MAX_BRIGHTNESS / 3
#endif


void pulsate_nb(uint32_t colour, uint32_t ramp_rate) {
	// ramp_rate is rate of change in brightness

	static uint32_t next_brightness = MAX_BRIGHTNESS;

	uint32_t current_brightness = leds.getBrightness();

	if (enabled) {
		leds.fill(colour);

		if (current_brightness == next_brightness) {
			// Set new brightness target
			next_brightness = map(random(50, 255), 50, 255, MIN_BRIGHTNESS, MAX_BRIGHTNESS);
		} else if (current_brightness < next_brightness) {
			leds.setBrightness(current_brightness + ramp_rate);
		} else if (current_brightness > next_brightness) {
			leds.setBrightness(current_brightness - ramp_rate);
		}
	}

	leds.show();
	lastUpdate = millis(); // time for next change to the display
}

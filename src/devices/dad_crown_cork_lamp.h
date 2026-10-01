/*
Demonstation with full-strip colour cycle, and colour cycle along the strip
*/

#define NUMLEDS 14
#define BRIGHTNESS (int) 255*0.8
#define NUM_PATTERNS 2

#include "animations/rainbow.h"
#include "animations/colour_wipe.h"

uint32_t colorwheel_2(uint32_t pos) {
	// Input a value 0 to 255 to get a color value.
	// The colours are a transition r - g - b - back to r.
	pos = pos%255;

	if (pos < 0 or pos > 255) {
		return leds.Color(0, 0, 0);
	};
	if (pos < 85) {
		return leds.Color(pos * 3, 255 - pos * 3, 0);
	};
	if (pos < 170) {
		pos -= 85;
		return leds.Color(255 - pos * 3, 0, pos * 3);
	};
	pos -= 170;
	return leds.Color(0, pos * 3, 255 - pos * 3);
}


uint8_t color_to_wheel_pos(uint8_t r, uint8_t g, uint8_t b){
	uint8_t pos = 0;

	if (r == 0) pos= (g/3 + 170);
    else if (g == 0) pos = (b/3 + 85);
    else if (b == 0) pos = (r/3);

	return pos % 255;
    
}

uint8_t color_to_wheel_pos(uint32_t color){
	uint8_t b = color & 0xFF;
	uint8_t g = (color >> 8) & 0xFF;
	uint8_t r = (color >> 16) & 0xFF;
	
	return color_to_wheel_pos(r, g, b);
}


void rainbow_along_nb_2() { // modified from Adafruit example to make it a state machine
	if (enabled) {
		leds.setBrightness(BRIGHTNESS);
	}

	static uint16_t j = 0;
	for (int i = 0; i < leds.numPixels(); i++) {
		uint16_t rc_index = (i * 256 /leds.numPixels()) + j;
		leds.setPixelColor(i, colorwheel(rc_index & 255));
	}

	leds.show();
	
	j++;
	
	if (j >= 256){
		j = 0;
	}
	lastUpdate = millis(); // time for next change to the display
}

unsigned long intervals [] = { 10, 50 } ; // speed for each pattern


uint16_t fade_reds [14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint16_t fade_blues [14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint16_t fade_greens [14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void fade_along_nb_2() {
	if (enabled) {
		leds.setBrightness(BRIGHTNESS);
	}

	// static int idx = 0;
	static uint8_t num_to_edit = 0;
	uint8_t step = 5;

	static int mode = 0;


	for (int i = 0; i <= num_to_edit; i++) {
		if (mode == 0){
			uint16_t current_r = fade_reds[i];
			current_r += step;
			if (current_r > 255) current_r = 255;
			leds.setPixelColor(i, leds.Color(current_r, 0, 0, 0));
			fade_reds[i] = current_r;
		}
		else if (mode == 1){
			uint16_t current_r = fade_reds[i];
			uint16_t current_b = fade_blues[i];

			current_b += step;
			if (current_b > 128) current_b = 128;

			current_r -= step;
			if (current_r < 128) current_r = 128;

			leds.setPixelColor(i, leds.Color(current_r, 0, current_b, 0));
			fade_reds[i] = current_r;
			fade_blues[i] = current_b;
		}	
		else if (mode == 2){
			int16_t current_r = fade_reds[i];
			uint16_t current_b = fade_blues[i];

			current_b += step;
			if (current_b > 255) current_b = 255;

			current_r -= step;
			if (current_r < 0) current_r = 0;

			leds.setPixelColor(i, leds.Color(current_r, 0, current_b, 0));
			fade_reds[i] = current_r;
			fade_blues[i] = current_b;
		}	else if (mode == 3){
			uint16_t current_b = fade_blues[i];
			uint16_t current_g = fade_greens[i];

			current_g += step;
			if (current_g > 128) current_g = 128;

			current_b -= step;
			if (current_b < 128) current_b = 128;

			leds.setPixelColor(i, leds.Color(0, current_g, current_b, 0));
			fade_greens[i] = current_g;
			fade_blues[i] = current_b;
		}			else if (mode == 4){
			int16_t current_b = fade_blues[i];
			uint16_t current_g = fade_greens[i];

			current_g += step;
			if (current_g > 255) current_g = 255;

			current_b -= step;
			if (current_b < 0) current_b = 0;

			leds.setPixelColor(i, leds.Color(0, current_g, current_b, 0));
			fade_greens[i] = current_g;
			fade_blues[i] = current_b;
		}		else if (mode == 5){
			uint16_t current_g = fade_greens[i];
			uint16_t current_r = fade_reds[i];

			current_r += step;
			if (current_r > 128) current_r = 128;

			current_g -= step;
			if (current_g < 128) current_g = 128;

			leds.setPixelColor(i, leds.Color(current_r, current_g, 0, 0));
			fade_reds[i] = current_r;
			fade_greens[i] = current_g;
		}			else if (mode == 6){
			int16_t current_g = fade_greens[i];
			uint16_t current_r = fade_reds[i];

			current_r += step;
			if (current_r > 255) current_r = 255;

			current_g -= step;
			if (current_g < 0) current_g = 0;

			leds.setPixelColor(i, leds.Color(current_r, current_g, 0, 0));
			fade_reds[i] = current_r;
			fade_greens[i] = current_g;
		}	
	}

	num_to_edit++;

	if (num_to_edit > 13) {
		num_to_edit = 13;

		if (mode == 0) {
			if (fade_reds[0] == 255) {
				num_to_edit = 0;
				mode = 1;
				}
		} else if (mode == 1) {
			if (fade_blues[0] == 128  && fade_blues[13] == 128 && fade_reds[13] == 128) {
				num_to_edit = 0;
				mode = 2;
				}
		} else if (mode == 2) {
			if (fade_blues[0] == 255 && fade_blues[12] == 255) {
				num_to_edit = 0;
				mode = 3;
				}
		} else if (mode == 3) {
			if (fade_greens[0] == 128  && fade_greens[13] == 128 && fade_blues[13] == 128) {
				num_to_edit = 0;
				mode = 4;
				}
		} else if (mode == 4) {
			if (fade_greens[0] == 255 && fade_greens[12] == 255) {
				num_to_edit = 0;
				mode = 5;
				}
		} else if (mode == 5) {
			if (fade_reds[0] == 128  && fade_reds[13] == 128 && fade_greens[13] == 128) {
				num_to_edit = 0;
				mode = 6;
				}
		} else if (mode == 6) {
			if (fade_reds[0] == 255 && fade_reds[12] == 255) {
				num_to_edit = 0;
				mode = 1;
				}
		}
	}




	leds.show();
	

	lastUpdate = millis(); // time for next change to the display
}


void updatePattern(uint8_t pat) { // call the pattern currently being created
	switch (pat) {
	case 0:
		rainbow_along_nb_2();
		break;
	case 1:
		// colour_wipe_nb();
		fade_along_nb_2();
		break;
	}
}

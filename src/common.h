#pragma once 
#include <Arduino.h>
// #include <tinyNeoPixel.h>
#include <tinyNeoPixel_Static.h>
#include <EEPROM.h>

// Pin mapping
// Button 2 changes mode
// Button 1 toggles power

#if defined(CROWN_CORK)
#define BTN1 PIN_PB1
#define BTN2 PIN_PB2
#define PIXEL PIN_PA7

#elif defined(PILL_POT)
#define BTN1 PIN_PA4  // Unused
#define BTN2 PIN_PA2
#define PIXEL PIN_PA1

#elif defined(ATTINY_RING)
#define BTN1 7	// PB0, not connected
#define BTN2 6	// PB1
#define PIXEL 8 // PA1

#elif defined(ATTINY_RING_412)
#define BTN1 0	// PA6
#define BTN2 1	// PA7, not connected
#define PIXEL 2 // PA1

#elif defined(ATTINY_STAR)
#define BTN1 7	// PB0, not connected
#define BTN2 2	// PA6
#define PIXEL 8 // PA1

#else
#define BTN1 8	// PA1
#define BTN2 9	// PA2
#define PIXEL 3 // PA7
// #define GPIO 0 // PA4

#endif 

// EEPROM Setting locations
#define EEPROM_ENABLED_ADDRESS 0
#define EEPROM_PATTERN_ADDRESS 8
#ifndef USE_EEPROM
#define USE_EEPROM 0
#endif

#define DEBOUNCE_DELAY 200  // ms

#ifndef NUMLEDS
#error "NUMLEDS not defined"
#endif

#ifndef BRIGHTNESS
#error "BRIGHTNESS not defined"
#endif

#ifndef DECAY_RATE
#error "DECAY_RATE not defined"
#endif

#ifndef NUM_PATTERNS
#error "NUM_PATTERNS not defined"
#endif

#ifndef COLOUR_ORDER
#define COLOUR_ORDER NEO_GRB
#endif

bool enabled = true; // Should the LEDs be on?
uint8_t pattern = 0;
unsigned long lastUpdate = 0;				  // for millis() when last update occoured

// tinyNeoPixel leds = tinyNeoPixel(NUMLEDS, PIXEL, COLOUR_ORDER);
// byte pixels[NUMLEDS * 3];
byte pixels[NUMLEDS * 4];
tinyNeoPixel leds = tinyNeoPixel(NUMLEDS, PIXEL, COLOUR_ORDER, pixels);

extern unsigned long intervals[];		  // speed for each pattern
// unsigned long patternInterval = intervals[0]; // time between steps in the pattern
unsigned long patternInterval; // time between steps in the pattern

extern void updatePattern(uint8_t pat); // call the pattern currently being created



// Some common colours
uint32_t RED = leds.Color(255, 0, 0, 0);
uint32_t YELLOW = leds.Color(255, 150, 0, 0);
uint32_t GREEN = leds.Color(0, 255, 0, 0);
uint32_t CYAN = leds.Color(0, 255, 255, 0);
uint32_t BLUE = leds.Color(0, 0, 255, 0);
uint32_t PURPLE = leds.Color(180, 0, 255, 0);

uint32_t colorwheel(uint32_t pos) {
	// Input a value 0 to 255 to get a color value.
	// The colours are a transition r - g - b - back to r.
	if (pos < 0 or pos > 255) {
		return leds.Color(0, 0, 0);
	};
	if (pos < 85) {
		return leds.Color(255 - pos * 3, pos * 3, 0);
	};
	if (pos < 170) {
		pos -= 85;
		return leds.Color(0, 255 - pos * 3, pos * 3);
	};
	pos -= 170;
	return leds.Color(pos * 3, 0, 255 - pos * 3);
}


void setup_controller() {
	// Configure buttons
	pinMode(BTN1, INPUT_PULLUP);
	pinMode(BTN2, INPUT_PULLUP);

	// Configure LEDs and turn them all off.
	pinMode(PIXEL, OUTPUT);
	leds.begin();
	leds.fill(0);
	leds.setBrightness(BRIGHTNESS);
	leds.show(); // LED turns on.
	delay(100);

	// // Load settings from EEPROM
	if (USE_EEPROM){
		enabled = EEPROM.read(EEPROM_ENABLED_ADDRESS);
		pattern = EEPROM.read(EEPROM_PATTERN_ADDRESS);
	}
	if (pattern >= NUM_PATTERNS)
		pattern = 0;					  // wrap round if too big
	patternInterval = intervals[pattern]; // set speed for this pattern
}




void loop_controller() {
	// static uint8_t pattern = 0, last_btn1_reading, last_btn2_reading;
	static int last_btn1_reading, last_btn2_reading;
	int btn1_reading = digitalRead(BTN1);
	int btn2_reading = digitalRead(BTN2);

	// Button 2, closer to MCU, changes mode
	// Button 1, closer to USB, toggles power

	if (btn1_reading == LOW && btn2_reading == LOW) {
		// Reset pattern
		pattern = 0;
		patternInterval = intervals[pattern]; // set speed for this pattern
		if (USE_EEPROM) EEPROM.update(EEPROM_PATTERN_ADDRESS, pattern);
		return;
	}

	if (last_btn2_reading == HIGH && btn2_reading == LOW) {
		pattern++; // change pattern number
		if (pattern >= NUM_PATTERNS)
			pattern = 0;					  // wrap round if too big
		patternInterval = intervals[pattern]; // set speed for this pattern
		leds.fill(0);
		if (USE_EEPROM) EEPROM.update(EEPROM_PATTERN_ADDRESS, pattern);
		delay(DEBOUNCE_DELAY); // debounce delay
	}
	last_btn2_reading = btn2_reading; // save for next time

	if (last_btn1_reading == HIGH && btn1_reading == LOW) {
		enabled = !enabled;
		if (USE_EEPROM) EEPROM.update(EEPROM_ENABLED_ADDRESS, enabled);
		delay(DEBOUNCE_DELAY); // debounce delay
	}
	last_btn1_reading = btn1_reading; // save for next time

	if (enabled) {
		if (millis() - lastUpdate > patternInterval)
			updatePattern(pattern);
	} else if (leds.getBrightness() > 0) {
		// Slow fade out
		if (millis() - lastUpdate > 1) {
			leds.setBrightness(leds.getBrightness() - DECAY_RATE);
			leds.show();
			lastUpdate = millis();
		}
	}
}


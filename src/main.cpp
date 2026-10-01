#include <Arduino.h>
// #include <tinyNeoPixel.h>
#include <tinyNeoPixel_Static.h>

#define DECAY_RATE 1 // For fade out

#include "device.h"
#include "common.h"



void setup() { setup_controller(); }



void loop() {
	loop_controller();
}


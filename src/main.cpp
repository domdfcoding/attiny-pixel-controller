#include <Arduino.h>
// #include <tinyNeoPixel.h>
#include <tinyNeoPixel_Static.h>

#define DECAY_RATE 1  // For fade out


#if defined(BLUE_CRYSTAL_FORMATION)
#include "devices/blue_crystal_formation.h"
#elif defined(DEMO)
#include "devices/demo.h"
#elif defined(HANGING_PLASTIC_STAR)
#include "devices/hanging_plastic_star.h"
#elif defined(TAHU_DIORAMA)
#include "devices/tahu_diorama.h"
#elif defined(SPAIN_LIGHTHOUSE)
#include "devices/spain_lighthouse.h"
#elif defined(HALLOWEEN_STAKE_LIGHTS)
#include "devices/halloween_stake_lights.h"
#elif defined(DEMO_814)
#include "devices/demo_814.h"
#elif defined(HALLOWEEN_SNAKE_JAR)
#include "devices/halloween_snake_jar.h"
#elif defined(XMAS_TREE)
#include "devices/xmas_tree.h"
#elif defined(ADA_XMAS_TREE)
#include "devices/ada_xmas_tree.h"
#elif defined(COOLING_TOWER)
#include "devices/cooling_tower.h"
#elif defined(EASTER_EGG_LAMP)
#include "devices/easter_egg_lamp.h"
#elif defined(CRYSTAL_FORMATION)
#include "devices/crystal_formation.h"
#elif defined(PATTERN_LAMP)
#include "devices/pattern_lamp.h"
#elif defined(SNOWGLOBE)
#include "devices/snowglobe.h"
#elif defined(CHRISTMAS_HOUSE)
#include "devices/christmas_house.h"
#elif defined(GLASS_BOTTLE)
#include "devices/glass_bottle.h"
#elif defined(CROWN_CORK)
#include "devices/crown_cork_lamp.h"
#elif defined(DAD_CROWN_CORK)
#include "devices/dad_crown_cork_lamp.h"
#elif defined(PILL_POT)
#include "devices/demo.h"
#else 
#error No device selected
#endif

#include "common.h"


void setup() {
  setup_controller();
}



void loop() {
	loop_controller();
}


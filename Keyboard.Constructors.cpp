
#include "Keyboard.h"

Keyboard::Keyboard() {
	instanceCounter++;
	if (instanceCounter > 1)
		error(MULTIPLE_KEYBOARD_INSTANCES);
}

Keyboard::~Keyboard() {
	instanceCounter--;
}


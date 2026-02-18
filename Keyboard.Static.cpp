
#include "Keyboard.h"

void Keyboard::reset() {
	keyCallBackPackets.clear();
}

void Keyboard::pushPacket(KeyCallBackPacket& packet) {
	keyCallBackPackets.push_back(packet);
}


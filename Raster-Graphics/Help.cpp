#include "Help.h"

Help::Help(Receiver& receiver) : mReceiver(receiver) {}

void Help::execute() {
	mReceiver.Help();
}

string Help::toString() const {
	return "help";
}
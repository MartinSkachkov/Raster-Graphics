#include "Load.h"

Load::Load(Receiver& receiver) : mReceiver(receiver){}

void Load::execute() {
	mReceiver.Load();
}

string Load::toString() const {
	return "load";
}
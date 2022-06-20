#include "Save.h"

Save::Save(Receiver& receiver) : mReceiver(receiver){}

void Save::execute() {
	mReceiver.Save();
}

string Save::toString() const {
	return "save";
}
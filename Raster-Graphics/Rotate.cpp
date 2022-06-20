#include "Rotate.h"

Rotate::Rotate(Receiver& receiver) : mReceiver(receiver) {}

void Rotate::execute() {
	mReceiver.Rotate();
}

string Rotate::toString() const {
	return "rotate";
}
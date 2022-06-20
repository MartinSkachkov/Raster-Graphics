#include "Monochrome.h"

Monochrome::Monochrome(Receiver& receiver) : mReceiver(receiver){}

void Monochrome::execute() {
	mReceiver.Monochrome();
}

string Monochrome::toString() const {
	return "monochrome";
}
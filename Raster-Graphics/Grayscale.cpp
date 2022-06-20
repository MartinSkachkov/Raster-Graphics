#include "Grayscale.h"

Grayscale::Grayscale(Receiver& receiver) : mReceiver(receiver){}

void Grayscale::execute() {
	mReceiver.Grayscale();
}

string Grayscale::toString() const {
	return "grayscale";
}
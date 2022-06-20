#include "Negative.h"

Negative::Negative(Receiver& receiver) : mReceiver(receiver){}

void Negative::execute() {
	mReceiver.Negative();
}

string Negative::toString() const {
	return "negative";
}
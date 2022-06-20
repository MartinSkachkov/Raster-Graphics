#include "Close.h"

Close::Close(Receiver& receiver) : mReceiver(receiver){}

void Close::execute() {
	mReceiver.Close();
}

string Close::toString() const {
	return "close";
}
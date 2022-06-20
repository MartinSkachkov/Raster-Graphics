#include "Exit.h"

Exit::Exit(Receiver& receiver):mReceiver(receiver){}

void Exit::execute() {
	mReceiver.Exit();
}

string Exit::toString() const {
	return "exit";
}
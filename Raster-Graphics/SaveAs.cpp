#include "SaveAs.h"

SaveAs::SaveAs(Receiver& receiver) : mReceiver(receiver){}

void SaveAs::execute() {
	mReceiver.SaveAs();
}

string SaveAs::toString() const {
	return "saveas";
}
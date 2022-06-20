#ifndef __GRAYSCALE_H_
#define __GRAYSCALE_H_
#include "ICommand.h"
#include "Receiver.h"
#include <iostream>
using namespace std;

class Grayscale : public ICommand {
private:
	Receiver& mReceiver;
public:
	Grayscale(Receiver& receiver);
	void execute() override;
	string toString() const override;
};

#endif

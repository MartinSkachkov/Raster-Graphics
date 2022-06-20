#ifndef __MONOCHROME_H_
#define __MONOCHROME_H_
#include "ICommand.h"
#include "Receiver.h"
#include <iostream>
using namespace std;

class Monochrome : public ICommand {
private:
	Receiver& mReceiver;
public:
	Monochrome(Receiver& receiver);
	void execute() override;
	string toString() const override;
};

#endif


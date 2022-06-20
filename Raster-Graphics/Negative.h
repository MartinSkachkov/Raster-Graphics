#ifndef __NEGATIVE_H_
#define __NEGATIVE_H_
#include "ICommand.h"
#include "Receiver.h"
#include <iostream>
using namespace std;

class Negative : public ICommand {
private:
	Receiver& mReceiver;
public:
	Negative(Receiver& receiver);
	void execute() override;
	string toString() const override;
};

#endif

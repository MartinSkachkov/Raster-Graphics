#ifndef __ROTATE_H_
#define __ROTATE_H_
#include "ICommand.h"
#include "Receiver.h"
#include <iostream>
using namespace std;

class Rotate : public ICommand {
private:
	Receiver& mReceiver;
public:
	Rotate(Receiver& receiver);
	void execute() override;
	string toString() const override;
};

#endif

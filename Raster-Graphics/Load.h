#ifndef __LOAD_H_
#define __LOAD_H_
#include "ICommand.h"
#include "Receiver.h"
#include <iostream>
using namespace std;

class Load :public ICommand {
private:
	Receiver& mReceiver;
public:
	Load(Receiver& receiver);
	void execute() override;
	string toString() const override;
};

#endif

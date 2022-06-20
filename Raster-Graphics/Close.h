#ifndef __CLOSE_H_
#define __CLOSE_H_
#include "ICommand.h"
#include "Receiver.h"
#include <iostream>
using namespace std;

class Close : public ICommand {
private:
	Receiver& mReceiver;
public:
	Close(Receiver& receiver);
	void execute() override;
	string toString() const override;
};

#endif
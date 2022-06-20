#ifndef __EXIT_H_
#define __EXIT_H_
#include "ICommand.h"
#include "Receiver.h"
#include <iostream>
using namespace std;

class Exit : public ICommand {
private:
	Receiver& mReceiver;
public:
	Exit(Receiver& receiver);
	void execute() override;
	string toString() const override;
};

#endif

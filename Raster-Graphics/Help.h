#ifndef __HELP_H_
#define __HELP_H_
#include "ICommand.h"
#include "Receiver.h"
#include <iostream>
using namespace std;

class Help : public ICommand {
private:
	Receiver& mReceiver;
public:
	Help(Receiver& receiver);
	void execute() override;
	string toString() const override;
};

#endif

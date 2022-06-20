#ifndef __SAVE_H_
#define __SAVE_H_
#include "ICommand.h"
#include "Receiver.h"
#include <iostream>
using namespace std;

class Save : public ICommand {
private:
	Receiver& mReceiver;
public:
	Save(Receiver& receiver);
	void execute() override;
	string toString() const override;
};

#endif

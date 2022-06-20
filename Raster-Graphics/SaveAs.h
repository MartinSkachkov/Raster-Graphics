#ifndef __SAVE_AS_
#define __SAVE_AS_
#include "ICommand.h"
#include "Receiver.h"
#include <iostream>
using namespace std;

class SaveAs : public ICommand {
private:
	Receiver& mReceiver;
public:
	SaveAs(Receiver& receiver);
	void execute() override;
	string toString() const override;
};

#endif

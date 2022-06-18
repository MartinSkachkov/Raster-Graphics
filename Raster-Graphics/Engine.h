#ifndef __ENGINE_H_
#define __ENGINE_H_
#include <iostream>
#include "Receiver.h"
#include "Invoker.h"

using namespace std;

class Engine {
private:
	Receiver mReceiver;
	Invoker mCommand;
public:
	Engine();
	void run() const;
};

#endif
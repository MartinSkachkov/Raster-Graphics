#ifndef __INVOKER_H_
#define __INVOKER_H_
#include "ICommand.h"
#include <vector>
#include <string>
using namespace std;

class Invoker {
private:
	vector<ICommand*> mCommands;
public:
	Invoker();
	Invoker(const vector<ICommand*> commands);
	~Invoker();

	void addCommand(ICommand*&& command);

	void execute(string& commandName);

};

#endif

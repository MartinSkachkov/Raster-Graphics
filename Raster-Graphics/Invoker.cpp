#include "Invoker.h"

Invoker::Invoker() : mCommands(vector<ICommand*>()) {
}

Invoker::Invoker(const vector<ICommand*> commands) : mCommands(commands) {
}

Invoker::~Invoker() {
	for (size_t i = 0; i < mCommands.size(); i++) {
		delete mCommands[i];
	}
	mCommands.clear();
}

void Invoker::addCommand(ICommand*&& command) {
	mCommands.push_back(move(command));
}

void Invoker::execute(const string& commandName) {
	for (size_t i = 0; i < this->mCommands.size(); i++) {
		if (this->mCommands[i]->toString() == commandName) {
			this->mCommands[i]->execute();
			return;
		}
	}

	throw "Command not supported!\n";
}
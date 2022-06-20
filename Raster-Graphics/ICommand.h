#ifndef __ICOMMAND_H_
#define __ICOMMAND_H_
#include <string>

class ICommand {
public:
	virtual void execute() = 0;
	virtual string toString() const = 0;
	//virtual void undo() = 0; //action will be the opposite of execute (stack)
	virtual ~ICommand() {}
};

#endif

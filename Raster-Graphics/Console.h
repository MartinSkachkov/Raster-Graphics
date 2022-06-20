#ifndef __CONSOLE_H_
#define __CONSOLE_H_
#include <iostream>
using namespace std;

struct Console {
	void RenderConsole() const;
	static void RenderHelp();
};

#endif

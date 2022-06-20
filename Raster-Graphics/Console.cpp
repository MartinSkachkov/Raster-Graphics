#include "Console.h"

void Console::RenderConsole() const{
	cout << "===== Welcome to Raster Graphics =====" << endl;
	cout << "Type help for more information" << endl;
}

void Console::RenderHelp() {
	cout << "===== Information =====" << endl;
	cout << "The following commands are supported:" << endl;
	cout << "open <file_path> -> opens <file>" << endl;
	cout << "close -> closes currently opened file" << endl;
	cout << "save -> saves the currently open file" << endl;
	cout << "saveas <file> -> saves the currently open file in <file>" << endl;
	cout << "help -> prints this information" << endl;
	cout << "exit -> exists the program" << endl;
}
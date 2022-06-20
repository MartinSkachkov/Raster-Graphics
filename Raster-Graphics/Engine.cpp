#include "Engine.h"
#include "Console.h"
#include "Load.h"
#include "Close.h"
#include "Save.h"
#include "SaveAs.h"
#include "Help.h"
#include "Exit.h"
#include "Grayscale.h"
#include "Monochrome.h"
#include "Negative.h"
#include "Rotate.h"
#include <string>

Engine::Engine() {
	mCommand.addCommand(new Load(mReceiver));
	mCommand.addCommand(new Close(mReceiver));
	mCommand.addCommand(new Save(mReceiver));
	mCommand.addCommand(new SaveAs(mReceiver));
	mCommand.addCommand(new Help(mReceiver));
	mCommand.addCommand(new Exit(mReceiver));
	mCommand.addCommand(new Grayscale(mReceiver));
	mCommand.addCommand(new Monochrome(mReceiver));
	mCommand.addCommand(new Negative(mReceiver));
	mCommand.addCommand(new Rotate(mReceiver));
}

void Engine::run() const {
#ifdef _WIN32
	system("cls");
#endif

#ifdef __unix__
	system("clear");
#endif
	Console console;
	console.RenderConsole();

	string input;
	while (true) {
		cout << ">";
		getline(cin, input);

	#ifdef _WIN32
			system("cls");
	#endif

	#ifdef __unix__
			system("clear");
	#endif

			try {
				mCommand.execute(input);
			}
			catch(const char* err){
				if (strcmp(err, "quit") == 0) {
					return;
				}
				cerr << err;
			}
	}

}
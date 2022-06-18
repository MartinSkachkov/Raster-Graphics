#include "Engine.h"
#include "Console.h"
#include command..
#include <string>
#define MAX_INPUT 20

Engine::Engine() {
	mCommand.addCommand();
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

	char input[MAX_INPUT];
	while (true) {
		cout << ">";
		cin.getline(input, MAX_INPUT);

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
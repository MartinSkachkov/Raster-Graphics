#include <iostream>
#include <cstring>
#include "Receiver.h"
#include "PBM.h"
#include "PGM.h"
#include "PPM.h"
#include "Image.h"
using namespace std;

//global variables
ifstream inputRaster;
ofstream outputRaster;
string baseFilename;
bool savedImage = false;
string path;
PBM imagePBM;
PGM imagePGM;
PPM imagePPM;

void Receiver::Load() {
	cout << ">load: ";
	string fullPath;
	cin >> fullPath;
	path = fullPath;

	//https://www.codegrepper.com/code-examples/cpp/c%2B%2B+get+filename+from+path
	baseFilename = fullPath.substr(fullPath.find_last_of("/\\") + 1); //gives file name with extension 
	inputRaster.open(baseFilename);

	//https://stackoverflow.com/questions/51949/how-to-get-file-extension-from-string-in-c
	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pbm") {
		imagePBM.load(inputRaster); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(fullPath.c_str());
		cout << "~Successfully opened " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pgm") {
		imagePGM.load(inputRaster); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(fullPath.c_str());
		cout << "~Successfully opened " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "ppm") {
		imagePPM.load(inputRaster); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(fullPath.c_str());
		cout << "~Successfully opened " << baseFilename << endl;
	}
}

bool Receiver::imageIsSaved()const {
	return savedImage;
}

void Receiver::Close() const {
	savedImage = false;
	cout << "~closing...\n";
	inputRaster.close();
	outputRaster.close();
	cout << "~Successfully closed " << baseFilename << endl;
}

void Receiver::Save() const {
	outputRaster.open(baseFilename);
	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pbm") {
		imagePBM.save(outputRaster); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully saved " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pgm") {
		imagePGM.save(outputRaster); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully saved " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "ppm") {
		imagePPM.save(outputRaster); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully saved " << baseFilename << endl;
	}
	savedImage = true;
}

void Receiver::SaveAs() const {
	string location;
	cout << ">Location: ";
	cin >> location;

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pbm") {
		imagePBM.saveAs(location.c_str()); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully saved " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pgm") {
		imagePGM.saveAs(location.c_str()); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully saved " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "ppm") {
		imagePPM.saveAs(location.c_str()); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully saved " << baseFilename << endl;
	}
}

void Receiver::Help() const {
	Console::RenderHelp();
}

void Receiver::Exit() const {
	if (!savedImage) {
		cout << "Image is not saved! Do you like to continue? y/n \n";
		char decision;
		do {
			cin >> decision;
			if (decision != 'y' && decision != 'n') {
				cout << "Invalid key typed! Type 'y' or 'n': ";
			}
		} while (decision != 'y' && decision != 'n');
		switch (decision)
		{
		case 'y': Save(); break;
		case 'n': Save(); break;
		}
	}
	savedImage = false;
	throw "quit";
}

void Receiver::Grayscale() {

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "ppm") {
		imagePPM.grayscale(); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully applied grayscale " << baseFilename << endl;
	}
}

void Receiver::Monochrome() {

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pgm") {
		imagePGM.monochrome(); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully applied monochrome " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "ppm") {
		imagePPM.monochrome(); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully applied monochrome " << baseFilename << endl;
	}
}

void Receiver::Negative() {
	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pbm") {
		imagePBM.negative(); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully applied negative " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pgm") {
		imagePGM.negative(); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully applied negative " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "ppm") {
		imagePPM.negative(); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully applied negative " << baseFilename << endl;
	}
}

void Receiver::Rotate() {
	cout << "Direction";
	string direction;
	cin >> direction;

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pbm") {
		imagePBM.rotate(direction.c_str()); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully applied" << direction << "rotation " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pgm") {
		imagePGM.rotate(direction.c_str()); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully applied" << direction << "rotation " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "ppm") {
		imagePPM.rotate(direction.c_str()); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully applied" << direction << "rotation " << baseFilename << endl;
	}
}

void Receiver::Collage() {
	cout << "Direction";
	string orientation;
	cin >> orientation;

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pbm") {
		imagePBM.collage(orientation.c_str()); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully applied" << orientation << "collage " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pgm") {
		imagePGM.collage(orientation.c_str()); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully applied" << orientation << "collage " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "ppm") {
		imagePPM.collage(orientation.c_str()); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(path.c_str());
		cout << "~Successfully applied" << orientation << "collage " << baseFilename << endl;
	}
}
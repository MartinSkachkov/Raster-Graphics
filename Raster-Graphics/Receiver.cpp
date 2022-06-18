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


void Receiver::Load() {
	cout << ">load: ";
	string fullPath;
	cin >> fullPath;

	//https://www.codegrepper.com/code-examples/cpp/c%2B%2B+get+filename+from+path
	baseFilename = fullPath.substr(fullPath.find_last_of("/\\") + 1); //gives file name with extension 
	inputRaster.open(baseFilename);

	//https://stackoverflow.com/questions/51949/how-to-get-file-extension-from-string-in-c
	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pbm") {
		PBM image;
		image.load(inputRaster); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(fullPath.c_str());
		cout << "~Successfully opened " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pgm") {
		PGM image;
		image.load(inputRaster); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(fullPath.c_str());
		cout << "~Successfully opened " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "ppm") {
		PPM image;
		image.load(inputRaster); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(fullPath.c_str());
		cout << "~Successfully opened " << baseFilename << endl;
	}
}

bool Receiver::imageIsSaved()const {
	return savedImage;
}

void Receiver::Close() const {
	cout << "~closing...\n";
	inputRaster.close();
	outputRaster.close();
	cout << "~Successfully closed " << baseFilename << endl;
}

void Receiver::Save() const {
	outputRaster.open(baseFilename);
	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pbm") {
		PBM image;
		image.save(outputRaster); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(fullPath.c_str());
		cout << "~Successfully opened " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "pgm") {
		PGM image;
		image.save(outputRaster); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(fullPath.c_str());
		cout << "~Successfully opened " << baseFilename << endl;
	}

	if (baseFilename.substr(baseFilename.find_last_of('.') + 1) == "ppm") {
		PPM image;
		image.save(outputRaster); //initializes MagicNum,Comment, Rows, Cols, MaxColVal vie a file input
		Image::setFilePath(fullPath.c_str());
		cout << "~Successfully opened " << baseFilename << endl;
	}

}


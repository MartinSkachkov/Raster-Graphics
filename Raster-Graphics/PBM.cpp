#include "PBM.h"

void PBM::free() {
	for (int i = 0; i < mRows; i++) {
		delete[] mPixels[i];
	}
	delete[] mPixels;
}

void PBM::copy(const PBM& other) {
	mPixels = new int*[other.mRows];
	for (size_t i = 0; i < other.mRows; i++){
		mPixels[i] = new int[other.mCols];
	}

	for (size_t i = 0; i < other.mRows; i++){
		for (size_t j = 0; j < other.mCols; j++){
			mPixels[i][j] = other.mPixels[i][j];
		}
	}
}

PBM::PBM(const char* filePath = "", const char* magicNum = "", const char* comment = "", unsigned int rows = 0, unsigned int cols = 0, unsigned int maxColorVal = 0) 
	: Image(filePath, magicNum, comment, rows, cols, maxColorVal) {
	mPixels = new int* [mRows];
	for (size_t i = 0; i < mRows; i++){
		mPixels[i] = new int[mCols];
	}
}

PBM::PBM(const PBM& other) : Image(other) {
	copy(other);
}

PBM& PBM::operator=(const PBM& other) {
	if (this == &other) {
		return *this;
	}
	free();
	copy(other);
	Image::operator=(other);
	return *this;
}

PBM::~PBM() {
	free();
}


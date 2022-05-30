#include "Image.h"

void Image::free() {
	delete[] mFilePath;
	delete[] mMagicNum;
	delete[] mComment;
}

void Image::setFilePath(const char* filePath) {
	mFilePath = new char[strlen(filePath) + 1];
	strcpy_s(mFilePath, strlen(filePath) + 1, filePath);
}

void Image::setMagicNumber(const char* magicNum) {
	mMagicNum = new char[strlen(magicNum) + 1];
	strcpy_s(mMagicNum, strlen(magicNum) + 1, magicNum);
}

void Image::setComment(const char* comment) {
	mComment = new char[strlen(comment) + 1];
	strcpy_s(mComment, strlen(comment) + 1, comment);
}

void Image::copy(const Image& other) {
	setFilePath(other.mFilePath);
	setMagicNumber(other.mMagicNum);
	setComment(other.mComment);

	mRows = other.mRows;
	mCols = other.mCols;
	mMaxVal = other.mMaxVal;
}

Image::Image(const char* filePath = "", const char* magicNum = "", const char* comment = "", unsigned int rows = 0, unsigned int cols = 0, unsigned int maxVal = 0)
: mRows(rows), mCols(cols), mMaxVal(maxVal) {
	setFilePath(filePath);
	setMagicNumber(magicNum);
	setComment(comment);
}

Image::Image(const Image& other) {
	copy(other);
}

Image& Image::operator=(const Image& other) {
	if (this == &other) {
		return *this;
	}
	free();
	copy(other);
	return *this;
}

Image::~Image() {
	free();
}

#include "Image.h"

void Image::free() {
	delete[] mFilePath;
	delete[] mMagicNum;
	delete[] mComment;
}

void Image::copy(const Image& other) {
	setFilePath(other.mFilePath);
	setMagicNumber(other.mMagicNum);
	setComment(other.mComment);

	mRows = other.mRows;
	mCols = other.mCols;
	mMaxColorVal = other.mMaxColorVal;
}

void Image::setFilePath(const char* filePath) {
	if (filePath == nullptr) {
		mFilePath = new char[1];
		mFilePath[0] = '\0';
		cout << "Empty file path!";
		return;
	}

	mFilePath = new char[strlen(filePath) + 1];
	strcpy_s(mFilePath, strlen(filePath) + 1, filePath);
}

void Image::setMagicNumber(const char* magicNum) {
	if (magicNum == nullptr) {
		mMagicNum = new char[1];
		mMagicNum[0] = '\0';
		cout << "Empty magic number!";
		return;
	}

	mMagicNum = new char[strlen(magicNum) + 1];
	strcpy_s(mMagicNum, strlen(magicNum) + 1, magicNum);
}

void Image::setComment(const char* comment) {
	if (comment == nullptr) {
		mComment = new char[1];
		mComment[0] = '\0';
		cout << "Empty comment!";
		return;
	}
	mComment = new char[strlen(comment) + 1];
	strcpy_s(mComment, strlen(comment) + 1, comment);
}

Image::Image(const char* filePath, const char* magicNum, const char* comment, unsigned int rows, unsigned int cols, unsigned int maxColorVal)
: mRows(rows), mCols(cols), mMaxColorVal(maxColorVal) {
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

const char* Image::getFilePath() const {
	return mFilePath;
}

const char* Image::getFileName() const {
	const char* path = getFilePath(); //mFilePath is protected
	size_t ind = 0;
	size_t pathLen = strlen(path);

	for (int i = pathLen - 1; i >= 0; i--) {
		if (path[i] == '\\' || path[i]) {
			break;
		}
		ind = i;
	}

	char* name = new char[pathLen - ind + 1];
	
	size_t i = 0;
	while (path[ind]) {
		name[i] = path[ind];
		i++;
		ind++;
	}
	name[i] = '\0';
	return name;
}


void Image::printFileName() const {
	cout << getFileName();
}


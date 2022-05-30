#ifndef __IMAGE_H_
#define __IMAGE_H_
#include <iostream>
using namespace std;

//abstract class - template for an Image
class Image {
private:
	void free();
	void copy(const Image& other);
protected:
	char* mFilePath;
	char* mMagicNum;
	char* mComment;
	unsigned int mRows;
	unsigned int mCols;
	unsigned int mMaxVal; //max color 255
public:
	void setFilePath(const char* filePath);
	void setMagicNumber(const char* magicNum);
	void setComment(const char* comment);

	Image(const char* filePath, const char* magicNum, const char* comment, unsigned int rows, unsigned int cols, unsigned int maxVal);
	Image(const Image& other);
	Image& operator=(const Image& other);
	virtual ~Image();

	virtual void load(istream& in) = 0;
	//virtual void close(fstream& file) = 0;
	virtual void save(ostream& out) = 0;
	virtual void saveAs(const char* location) = 0;

	virtual void grayscale() = 0;
	virtual void monochrome() = 0;
	virtual void negative() = 0;
	virtual void rotate(const char* direction) = 0;
	virtual void collage(const char* orientation) = 0; //?

	virtual Image* clone() const = 0;
};

#endif

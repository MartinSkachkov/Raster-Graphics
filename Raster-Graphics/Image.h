#ifndef __IMAGE_H_
#define __IMAGE_H_
#include <iostream>
#include <fstream>
using namespace std;

//abstract class - template for an Image
class Image {
private:
	void free();
	void copy(const Image& other);
protected:
	static char* mFilePath;
	char* mMagicNum;
	char* mComment;
	unsigned int mRows;
	unsigned int mCols;
	unsigned int mMaxColorVal; //max color 255
public:
	static void setFilePath(const char* filePath);
	void setMagicNumber(const char* magicNum);
	void setComment(const char* comment);

	Image(const char* filePath = "", const char* magicNum = "", const char* comment = "", unsigned int rows = 0, unsigned int cols = 0, unsigned int maxColorVal = 0);
	Image(const Image& other);
	Image& operator=(const Image& other);
	virtual ~Image();

	const char* getFilePath() const;
	const char* getFileName() const;
	void printFileName() const;

	virtual void load(istream& in) = 0;
	virtual void save(ostream& out) const = 0;
	virtual void saveAs(const char* location) const = 0;

	virtual void grayscale() = 0;
	virtual void monochrome() = 0;
	virtual void negative() = 0;
	virtual void rotate(const char* direction) = 0;
	virtual void collage(const char* orientation) = 0; //?

	virtual Image* clone() const = 0;
};

#endif

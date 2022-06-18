#ifndef __PGM_H_
#define __PGM_H_
#include "Image.h"

// 0 signifies a black pixel, and maxVal signifies a white pixel
// P1
// #comment
// cols rows
// maxVal = 255

class PGM : public Image {
private:
	int** mPixels;
	void free();
	void copy(const PGM& other);
public:
	PGM(const char* filePath = "", const char* magicNum = "", const char* comment = "", unsigned int rows = 0, unsigned int cols = 0, unsigned int maxColorVal = 0);
	PGM(const PGM& other);
	PGM& operator=(const PGM& other);
	~PGM();

	virtual void load(istream& in) override;
	virtual void save(ostream& out) const override;
	virtual void saveAs(const char* location)const override;

	virtual void monochrome() override;
	virtual void negative() override;
	virtual void rotate(const char* direction) override;
	virtual void collage(const char* orientation) override;//todo

	virtual Image* clone() const override;

private:
	unsigned int Threshold() const;
	void RightRotation(); //possible error
	//functions that are just needed to be able to create an object
	virtual void grayscale() override;
};

#endif

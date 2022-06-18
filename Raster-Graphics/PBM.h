#ifndef __PBM_H_
#define __PBM_H_
#include "Image.h"

//0 signifies a white pixel, and a 1 signifies a black pixel
// P1
// #comment
// cols rows
// maxVal = 1
//0 0 1 
//1 0 1 
//0 1 0 

class PBM : public Image {
private:
	int** mPixels; //image
	void free();
	void copy(const PBM& other);
public:
	PBM(const char* filePath = "", const char* magicNum = "", const char* comment = "", unsigned int rows = 0, unsigned int cols = 0, unsigned int maxColorVal = 0);
	PBM(const PBM& other);
	PBM& operator=(const PBM& other);
	~PBM();

	virtual void load(istream& in) override;
	virtual void save(ostream& out) const override;
	virtual void saveAs(const char* location) const override;

	virtual void negative() override;
	virtual void rotate(const char* direction) override;
	virtual void collage(const char* orientation) override; //todo

	virtual Image* clone() const override;

private:
	void RightRotation(); //possible error
	//functions that are just needed to be able to create an object
	virtual void grayscale() override;
	virtual void monochrome() override;
};

#endif

#ifndef __PPM_H_
#define __PPM_H_
#include "Image.h"
#include "RGB.h"

class PPM : public Image {
private:
	RGB** mPixels;
	void free();
	void copy(const PPM& other);
public:
	PPM(const char* filePath = "", const char* magicNum = "", const char* comment = "", unsigned int rows = 0, unsigned int cols = 0, unsigned int maxColorVal = 0);
	PPM(const PPM& other);
	PPM& operator=(const PPM& other);
	~PPM();

	virtual void load(istream& in) override;
	virtual void save(ostream& out) const override;
	virtual void saveAs(const char* location)const override;


	virtual void monochrome() override;
	virtual void grayscale() override;
	virtual void negative() override;
	virtual void rotate(const char* direction) override;
	virtual void collage(const char* orientation) override;//todo

	virtual Image* clone() const override;

private:
	unsigned int Threshold() const;
	void RightRotation(); //possible error
};

#endif

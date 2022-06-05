#ifndef __PBM_H_
#define __PBM_H_
#include "Image.h"

//0 signifies a white pixel, and a 1 signifies a black pixel
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

	virtual void load(istream& in) const override;
	//virtual void close(fstream& file) override;
	virtual void save(ostream& out) const override;
	virtual void saveAs(const char* location) const override;

	virtual void negative() = 0;
	virtual void rotate(const char* direction) = 0;
	virtual void collage(const char* orientation) = 0; //?

	virtual Image* clone() const override;
};

#endif

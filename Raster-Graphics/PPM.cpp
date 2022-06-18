#include "PPM.h"

void PPM::free() {
	for (size_t i = 0; i < mRows; i++) {
		delete[] mPixels[i];
	}
	delete[] mPixels; //calls the destructor for RGB as well
}

void PPM::copy(const PPM& other) {
	mPixels = new RGB * [other.mRows];
	for (size_t i = 0; i < other.mRows; i++) {
		mPixels[i] = new RGB[other.mCols];
	}

	for (size_t i = 0; i < other.mRows; i++) {
		for (size_t j = 0; j < other.mCols; j++) {
			mPixels[i][j] = other.mPixels[i][j];
		}
	}
}

PPM::PPM(const char* filePath, const char* magicNum, const char* comment, unsigned int rows, unsigned int cols, unsigned int maxColorVal)
	: Image(filePath, magicNum, comment, rows, cols, maxColorVal) {
	mPixels = new RGB * [mRows];
	for (size_t i = 0; i < mRows; i++) {
		mPixels[i] = new RGB[mCols];
	}
}

PPM::PPM(const PPM& other) : Image(other) {
	copy(other);
}

PPM& PPM::operator=(const PPM& other) {
	if (this == &other) {
		return *this;
	}
	free();
	copy(other);
	Image::operator=(other);
	return *this;
}

PPM::~PPM() {
	free();
}

void PPM::load(istream& in) {
	in.getline(mMagicNum, strlen(mMagicNum), '\n');
	if (mMagicNum[0] != 'P') {
		cout << "Invalid file format!";
	}

	in.getline(mComment, strlen(mComment), '.');
	in >> mCols;
	in >> mRows;
	in >> mMaxColorVal;


	for (unsigned int rows = 0; rows < mRows; rows++) {
		for (unsigned int cols = 0; cols < mCols; cols++) {
			if (in.good()) {
				in >> mPixels[rows][cols];
			}
		}
	}
}


void PPM::save(ostream& out) const {
	out << mMagicNum << endl;
	out << mComment << endl;
	out << mCols << ' ' << mRows << endl;
	out << mMaxColorVal << endl;

	for (unsigned int rows = 0; rows < mRows; rows++) {
		for (unsigned int cols = 0; cols < mCols; cols++) {
			if (out.good()) {
				if (cols == mCols - 1) {
					out << mPixels[rows][cols] << endl;
				}
				else {
					out << mPixels[rows][cols];
				}
			}
		}
	}
}

void PPM::saveAs(const char* direction) const {
	ofstream fileOut(direction);
	if (!fileOut.is_open()) {
		throw "Couldn't open the file!";
	}
	save(fileOut);
	fileOut.close();
}

void PPM::monochrome() {
	//https://www.dynamsoft.com/blog/insights/image-processing/image-processing-101-color-space-conversion/
		//used the information above

	unsigned int threshold = Threshold();
	// If the intensity level of a pixel is smaller than the threshold, 
	//the pixel is set to black (grayscale = 0). Otherwise, it is set to white (grayscale = 255).

	unsigned int black = 0;
	for (unsigned int rows = 0; rows < mRows; rows++) {
		for (unsigned int cols = 0; cols < mCols; cols++) {
			unsigned int pixelVal = (mPixels[rows][cols].red + mPixels[rows][cols].green + mPixels[rows][cols].blue) / 3;//making a pixel grayscale
			if (pixelVal < threshold) {
				mPixels[rows][cols].red = black;
				mPixels[rows][cols].green = black;
				mPixels[rows][cols].blue = black;
			}
			else if (pixelVal >= threshold) {
				mPixels[rows][cols].red = mMaxColorVal;
				mPixels[rows][cols].green = mMaxColorVal;
				mPixels[rows][cols].blue = mMaxColorVal;
			}
		}
	}
}


unsigned int PPM::Threshold() const {
	//used sources
	//https://datacarpentry.org/image-processing/07-thresholding/
	// https://www.baeldung.com/cs/convert-rgb-to-grayscale
	//In thresholding, we convert an image from colour or grayscale into a binary image, i.e., one that is simply black and white.
	unsigned int sum = 0;
	for (size_t rows = 0; rows < mRows; rows++) {
		for (size_t cols = 0; cols < mCols; cols++) {
			//since we have red, green and blue value per pixel
			size_t pixelVal = (mPixels[rows][cols].red + mPixels[rows][cols].green + mPixels[rows][cols].blue) / 3; //the average method
			sum += pixelVal;
		}
	}

	unsigned int threshold = sum / (mRows * mCols);
	return threshold;
}

void PPM::grayscale() {
	//https://www.baeldung.com/cs/convert-rgb-to-grayscale
	//https://web.stanford.edu/class/cs101/image-6-grayscale-adva.html
	//using the luminosity method
	//grayscale = 0.3 * R + 0.59 * G + 0.11 * B

	const double R_CONST = 0.3;
	const double G_CONST = 0.59;
	const double B_CONST = 0.11;

	size_t originalRed = 0;
	size_t originalGreen = 0;
	size_t originalBlue = 0;

	for (size_t rows = 0; rows < mRows; rows++) {
		for (size_t cols = 0; cols < mCols; cols++)
		{
			originalRed = mPixels[rows][cols].red;
			originalGreen = mPixels[rows][cols].green;
			originalBlue = mPixels[rows][cols].blue;

			mPixels[rows][cols].red = (R_CONST * originalRed) + (G_CONST * originalGreen) + (B_CONST * originalBlue);
			mPixels[rows][cols].green = (R_CONST * originalRed) + (G_CONST * originalGreen) + (B_CONST * originalBlue);
			mPixels[rows][cols].blue = (R_CONST * originalRed) + (G_CONST * originalGreen) + (B_CONST * originalBlue);
		}

	}
}

void PPM::negative() {
	//the image is loaded
	//formula: new_intensity = max_intensity - old_intensity.
	for (size_t rows = 0; rows < mRows; rows++) {
		for (size_t cols = 0; cols < mCols; cols++) {
			mPixels[rows][cols].red = mMaxColorVal - mPixels[rows][cols].red;
			mPixels[rows][cols].green = mMaxColorVal - mPixels[rows][cols].green;
			mPixels[rows][cols].blue = mMaxColorVal - mPixels[rows][cols].blue;
		}
	}
}

void PPM::rotate(const char* direction) {
	//rotation of a matrix
	if (strcmp(direction, "right") == 0) {
		RightRotation();
	}
	else {
		throw "Error in rotation!";
	}
	if (strcmp(direction, "left") == 0) {
		//we flip the image three times right hand side to achieve the left rotation
		for (size_t rotation = 0; rotation < 3; rotation++) {
			RightRotation();
		}
	}
	else {
		throw "Error in rotation!";
	}
}


void PPM::RightRotation() {
	//allocate memory for the the new Image
	RGB** newImage = new RGB * [mCols];
	for (size_t rows = 0; rows < mCols; rows++) {
		newImage[rows] = new RGB[mRows];
	}

	/*
	Ignore:
	copy the loaded one into the new Image
	for (size_t rows = 0; rows < mRows; rows++) {
		for (size_t cols = 0; cols < mCols; cols++) {
			newImage[rows][cols] = mPixels[rows][cols];
		}
	}*/

	//reversing the image
	 // Hint: Map each source element indices into
	  // indices of destination matrix element.
	  //dest_buffer[c][m - r - 1] = source_buffer[r][c];

	for (size_t rows = 0; rows < mRows; rows++) {
		for (size_t cols = 0; cols < mCols; cols++) {
			newImage[cols][mRows - rows - 1] = mPixels[rows][cols];
		}
	}

	int tempRows = mRows;
	mRows = mCols;
	mCols = mRows;

	for (size_t i = 0; i < mRows; i++) {
		delete[] mPixels[i];
	}
	delete[] mPixels;
	mPixels = newImage;
}

void PPM::collage(const char* orientation) {
	//todo
}

Image* PPM::clone() const {
	return new PPM(*this);
}
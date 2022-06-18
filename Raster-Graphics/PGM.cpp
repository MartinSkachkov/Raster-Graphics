#include "PGM.h"

void PGM::free() {
	for (unsigned int i = 0; i < mRows; i++) {
		delete[] mPixels[i];
	}
	delete[] mPixels;
}

void PGM::copy(const PGM& other) {
	mPixels = new int* [other.mRows];
	for (size_t i = 0; i < other.mRows; i++) {
		mPixels[i] = new int[other.mCols];
	}

	for (size_t i = 0; i < other.mRows; i++) {
		for (size_t j = 0; j < other.mCols; j++) {
			mPixels[i][j] = other.mPixels[i][j];
		}
	}
}

PGM::PGM(const char* filePath, const char* magicNum, const char* comment, unsigned int rows, unsigned int cols, unsigned int maxColorVal)
	: Image(filePath, magicNum, comment, rows, cols, maxColorVal) {
	mPixels = new int* [mRows];
	for (size_t i = 0; i < mRows; i++) {
		mPixels[i] = new int[mCols];
	}
}

PGM::PGM(const PGM& other) : Image(other) {
	copy(other);
}

PGM& PGM::operator=(const PGM& other) {
	if (this == &other) {
		return *this;
	}
	free();
	copy(other);
	Image::operator=(other);
	return *this;
}

PGM::~PGM() {
	free();
}

void PGM::load(istream& in) {
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

void PGM::save(ostream& out) const {
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


void PGM::saveAs(const char* direction) const {
	ofstream fileOut(direction);
	if (!fileOut.is_open()) {
		throw "Couldn't open the file!";
	}
	save(fileOut);
	fileOut.close();
}

void PGM::monochrome() {
//https://www.dynamsoft.com/blog/insights/image-processing/image-processing-101-color-space-conversion/
	//used the information above

	unsigned int threshold = Threshold();
	// If the intensity level of a pixel is smaller than the threshold, 
	//the pixel is set to black (grayscale = 0). Otherwise, it is set to white (grayscale = 255).

	unsigned int black = 0;
	for (unsigned int rows = 0; rows < mRows; rows++) {
		for (unsigned int cols = 0; cols < mCols; cols++) {
			if (unsigned(mPixels[rows][cols]) < threshold) {
				mPixels[rows][cols] = black;
			}
			else if (unsigned(mPixels[rows][cols]) >= threshold) {
				mPixels[rows][cols] = mMaxColorVal;
			}
		}
	}
}

unsigned int PGM::Threshold() const {
	//https://datacarpentry.org/image-processing/07-thresholding/
	//https://tutorialbit.com/digital-image-processing/single-value-threshold-from-image-histogram-image-segmentation/
	unsigned int sum = 0;
	for (size_t rows = 0; rows < mRows; rows++) {
		for (size_t cols = 0; cols < mCols; cols++) {
			sum += mPixels[rows][cols];
		}
	}

	unsigned int threshold = sum / (mRows * mCols);
	return threshold;
}

void PGM::negative() {
	//the image is loaded
	//formula: new_intensity = max_intensity - old_intensity.
	for (size_t rows = 0; rows < mRows; rows++) {
		for (size_t cols = 0; cols < mCols; cols++) {
			mPixels[rows][cols] = mMaxColorVal - mPixels[rows][cols];
		}
	}
}

void PGM::rotate(const char* direction) {
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

void PGM::RightRotation() {
	//allocate memory for the the new Image
	int** newImage = new int* [mCols];
	for (size_t rows = 0; rows < mCols; rows++) {
		newImage[rows] = new int[mRows];
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

void PGM::collage(const char* orientation) {
	//todo
}

Image* PGM::clone() const {
	return new PGM(*this);
}

void PGM::grayscale() {
}
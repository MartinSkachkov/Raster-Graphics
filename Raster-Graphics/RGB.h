#ifndef __RGB_H_
#define __RGB_H_
#include <iostream>
using namespace std;

struct RGB {
	size_t red;
	size_t green;
	size_t blue;

	RGB();
	friend istream& operator>>(istream& in, RGB& pixel);
	friend ostream& operator<<(ostream& out, const RGB& pixel);
};

#endif
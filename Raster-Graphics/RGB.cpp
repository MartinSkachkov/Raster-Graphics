#include "RGB.h"

RGB::RGB() {
	red = 0;
	green = 0;
	blue = 0;
}

istream& operator>>(istream& in, RGB& pixel) {
	return in >> pixel.red >> pixel.green >> pixel.blue;
}

ostream& operator<<(ostream& out, const RGB& pixel) {
	return out << pixel.red << ' ' << pixel.green << ' ' << pixel.blue;
}
// RGB.h

#ifndef RGB_H_
#define RGB_H_

namespace rjm {

struct RGB {
	double r;
	double g;
	double b;

	RGB(double r, double g, double b);

};

RGB operator-(const RGB &first, const RGB &second);

} /* namespace rjm */

#endif /* RGB_H_ */
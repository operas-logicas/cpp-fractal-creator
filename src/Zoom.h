// Zoom.h

#ifndef ZOOM_H_
#define ZOOM_H_

namespace rjm {

struct Zoom {
	int x{0};
	int y{0};
	double scale{0.0};

	Zoom(int x, int y, double scale): x(x), y(y), scale(scale) {

	}
};

} /* namespace rjm */

#endif /* ZOOM_H_ */
// ZoomList.h

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility>

using namespace std;

namespace rjm {

class ZoomList {
private:
	int m_width{0};
	int m_height{0};
	vector<Zoom> zooms;
	double m_xCenter{0.0};
	double m_yCenter{0.0};
	double m_scale{1.0};

public:
	ZoomList(int width, int height);
	void add(const Zoom &zoom);
	pair<double, double> doZoom(int x, int y);

};

} /* namespace rjm */

#endif /* ZOOMLIST_H_ */
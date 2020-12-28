// FractalCreator.h

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include <utility>
#include "ZoomList.cpp"
#include "Screen.cpp"
#include "Mandelbrot.cpp"
#include "RGB.cpp"

using namespace std;

namespace rjm {

class FractalCreator {
private:
	int m_width;
	int m_height;
	unique_ptr<int[]> m_histogram;
	unique_ptr<int[]> m_fractal;
	ZoomList m_zoomList;
	Screen m_screen;

	int m_total{0};

	vector<int> m_ranges;
	vector<RGB> m_colors;
	vector<int> m_rangeTotals;

	bool m_bGotFirstRange{false};

private:
	void calculateIteration();
	void calculateTotalIterations();
	void calculateRangeTotals();
	void drawFractal();
	void update(int x, int y);

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void addRange(double rangeEnd, const RGB &rgb);
	void addZoom(const Zoom &zoom);
	int getRange(int iterations) const;
	void run();
	bool processEvents();	

};

} /* namespace rjm */

#endif /* FRACTALCREATOR_H_ */
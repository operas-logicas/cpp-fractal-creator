// main.cpp

#include <iostream>
#include "FractalCreator.cpp"

using namespace std;
using namespace rjm;

int main(int argc, char *argv[]) {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	FractalCreator fractalCreator(SCREEN_WIDTH, SCREEN_HEIGHT);

	fractalCreator.addRange(0.0, RGB(0, 0, 255));
	fractalCreator.addRange(0.05, RGB(255, 99, 71));
	fractalCreator.addRange(0.08, RGB(255, 215, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 255));

	fractalCreator.run();

	while(true) {

		if(fractalCreator.processEvents() == false) break;
	
	}


	return 0;
}
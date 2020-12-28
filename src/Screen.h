// Screen.h

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace rjm {

class Screen {
private:
	int m_width;
	int m_height;

	SDL_Window *m_window{NULL};
	SDL_Renderer *m_renderer{NULL};
	SDL_Texture *m_texture{NULL};
	unique_ptr<Uint32[]> m_buffer;

public:
	Screen(int width, int height);
	bool init();
	void clear();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void close();

};


} /* namespace rjm */

#endif /* SCREEN_H_ */
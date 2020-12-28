// Screen.cpp

#include <cstring>
#include "Screen.h"

namespace rjm {

Screen::Screen(int width, int height): m_width(width), m_height(height) {

}


bool Screen::init() {

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	m_window = SDL_CreateWindow("Fractal Creator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		m_width, m_height, SDL_WINDOW_SHOWN);
	if(m_window == NULL) {
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	if(m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, m_width, m_height);
	if(m_texture == NULL) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_buffer.reset(new Uint32[m_width*m_height*sizeof(Uint32)]{0});

	return true;

}


void Screen::clear() {

	m_buffer.reset(new Uint32[m_width*m_height*sizeof(Uint32)]{0});

}


void Screen::update() {

	SDL_UpdateTexture(m_texture, NULL, m_buffer.get(), m_width*sizeof(Uint32));
	SDL_RenderClear(m_renderer);	
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);	
	SDL_RenderPresent(m_renderer);
	
}


void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

	if(x < 0 || x >= m_width || y < 0 || y >= m_height) return;

	Uint32 color = 0;

	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<=8;
	color += 0xFF;

	m_buffer[(y * m_width) + x] = color;

}


void Screen::close() {

	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);	
	SDL_DestroyWindow(m_window);

}


} /* namespace rjm */
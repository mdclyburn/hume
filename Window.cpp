#include "Window.h"

namespace hm
{
	Window::Window()
	{
		width = 640;
		height = 480;
		window = SDL_CreateWindow("No Title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
		if(window == nullptr)
			std::cout << "SDL_Window creation failed.";
		else
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}

	Window::Window(int w, int h)
	{
		width = w;
		height = h;
		window = SDL_CreateWindow("No Title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0);
		if(window == nullptr)
			std::cout << "SDL_Window creation failed.";
		else
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}

	Window::Window(std::string title, int w, int h)
	{
		width = w;
		height = h;
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0);
		if(window == nullptr)
			std::cout << "SDL_Window creation failed.";
		else
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}

	Window::~Window()
	{
		// Nothing to do here.
	}

	void Window::setTitle(std::string title)
	{
		SDL_SetWindowTitle(window, title.c_str());
		return;
	}
	
	bool Window::getStatus()
	{
		return (window != nullptr);
	}

	void Window::draw(Blittable& b)
	{
		// Don't draw if transparent. Waste of resources.
		if(b.getAlpha() == TRANSPARENT)
			return;
		clear();
		SDL_RenderCopy(renderer, b.getTexture(), nullptr, b.getPosition());
		needRefresh = true;
		return;
	}

	void Window::draw(Blittable& b, int x, int y)
	{
		// Don't draw if transparent. Waste of resources.
		if(b.getAlpha() == TRANSPARENT)
			return;
		clear();
		SDL_Rect sdlr;
		sdlr.x = x;
		sdlr.y = y;
		SDL_RenderCopy(renderer, b.getTexture(), nullptr, &sdlr);
		return;
	}
	
	void Window::clear()
	{
		// Don't clear the window if there are changes pending.
		if(!needRefresh)
			SDL_RenderClear(renderer);
		return;
	}

	void Window::refresh()
	{

		if(needRefresh)
		{
			SDL_RenderPresent(renderer);
			needRefresh = false;
		}

		return;
	}

	int Window::getWidth()
	{
		return width;
	}

	int Window::getHeight()
	{
		return height;
	}
}

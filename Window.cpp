#include "Window.h"

namespace hm
{
	Window::Window() : window(nullptr), renderer(nullptr)
	{
		create();
	}
	
	Window::Window(WindowSettings ws) : window(nullptr), renderer(nullptr), settings(ws)
	{
		create();
	}
	
	Window::~Window()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
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
		SDL_Rect sdlr = b.getInfo();
		SDL_RenderCopy(renderer, b.getTexture(), nullptr, &sdlr);
		needRefresh = true;
		return;
	}

	void Window::draw(Blittable& b, int x, int y)
	{
		// Don't draw if transparent. Waste of resources.
		if(b.getAlpha() == TRANSPARENT)
			return;
		SDL_Rect sdlr = b.getInfo();
		sdlr.x = x;
		sdlr.y = y;
		SDL_RenderCopy(renderer, b.getTexture(), nullptr, &sdlr);
		return;
	}
	
	void Window::draw(Blittable& b, int x, int y, int w, int h)
	{
		// Don't draw if transparent. Waste of resources.
		if(b.getAlpha() == TRANSPARENT)
			return;
		SDL_Rect sdlr = { x, y, w, h };
		SDL_RenderCopy(renderer, b.getTexture(), nullptr, &sdlr);
		return;
	}
	
	void Window::clear()
	{
		SDL_RenderClear(renderer);
		return;
	}
	
	void Window::forceRefresh()
	{
		needRefresh = true;
		return;
	}

	void Window::refresh()
	{
		SDL_RenderPresent(renderer);
		return;
	}

	int Window::getWidth()
	{
		return settings.getResolution().width;
	}

	int Window::getHeight()
	{
		return settings.getResolution().height;
	}
	
	// Centers the given Blittable in the given Window.
	void Window::center(Blittable& b)
	{
		b.setx(settings.getResolution().width / 2 - b.getWidth() / 2);
		b.sety(settings.getResolution().height / 2 - b.getHeight() / 2);
		
		return;
	}
	
	// Centers the given Blittable on the X-Axis in the given window.
	void Window::centerx(Blittable& b)
	{
		b.setx(settings.getResolution().width / 2 - b.getWidth() / 2);
		return;
	}
	
	// Centers the given Blittable on the Y-Axis in the given window.
	void Window::centery(Blittable& b)
	{
		b.sety(settings.getResolution().height / 2 - b.getHeight() / 2);
		return;
	}
	
	void Window::centerxco(Blittable& b, int x)
	{
		b.setx(x - b.getWidth() / 2);
		return;
	}
	
	void Window::centeryco(Blittable& b, int y)
	{
		b.sety(y - b.getHeight() / 2);
		return;
	}
	
	void Window::centerco(Blittable& b, int x, int y)
	{
		centerxco(b, x);
		centeryco(b, y);
		return;
	}
	
	void Window::top(Blittable& b)
	{
		b.sety(0);
		return;
	}
	
	void Window::bottom(Blittable& b)
	{
		b.sety(settings.getResolution().height - b.getHeight());
		return;
	}
	
	void Window::left(Blittable& b)
	{
		b.setx(0);
		return;
	}
	
	void Window::right(Blittable& b)
	{
		b.setx(settings.getResolution().width - b.getWidth());
		return;
	}
	
	SDL_Renderer* Window::getRenderer()
	{
		return renderer;
	}
	
	WindowSettings Window::getSettings()
	{
		return settings;
	}
	
	void Window::create()
	{
		// Safeguard against creating another window.
		if(window != nullptr)
		{
			Logger::getLogger()->log("Window creation requested, but a window already exists.", WARNING);
			return;
		}
		
		if(settings.isFullscreen())
		{
			window = SDL_CreateWindow(settings.getTitle().c_str(),
									  SDL_WINDOWPOS_UNDEFINED,
									  SDL_WINDOWPOS_UNDEFINED,
									  settings.getResolution().width,
									  settings.getResolution().height,
									  SDL_WINDOW_FULLSCREEN);
		}
		else
		{
			window = SDL_CreateWindow(settings.getTitle().c_str(),
									  SDL_WINDOWPOS_UNDEFINED,
									  SDL_WINDOWPOS_UNDEFINED,
									  settings.getResolution().width,
									  settings.getResolution().height,
									  0);
		}
		
		if(window == nullptr)
		{
			Logger::getLogger()->log("SDL_Window creation failed.", ERROR);
			exit(0);
		}
		
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if(renderer == nullptr)
		{
			Logger::getLogger()->log("SDL_Renderer creation failed.", ERROR);
			exit(0);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		
		return;
	}
}

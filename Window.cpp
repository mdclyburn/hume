// Hume Library Version 0.6

#include "Window.h"

namespace hm
{
	Window::Window() : window(nullptr), renderer(nullptr)
	{
		create();
	}
	
	Window::Window(const WindowSettings& ws) : window(nullptr), renderer(nullptr), settings(ws)
	{
		create();
	}
	
	Window::~Window()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
	}

	void Window::setTitle(const std::string& title)
	{
		SDL_SetWindowTitle(window, title.c_str());
		return;
	}
	
	bool Window::getStatus() const
	{
		return (window != nullptr);
	}

	void Window::draw(const Blittable& b)
	{
		// Don't draw if transparent. Waste of resources.
		if(b.getAlpha() == TRANSPARENT)
			return;
		SDL_Rect sdlr = b.getInfo();
		SDL_RenderCopy(renderer, b.getTexture(), nullptr, &sdlr);
		needRefresh = true;
		return;
	}

	void Window::draw(const Blittable& b, int x, int y)
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
	
	void Window::draw(const Blittable& b, int x, int y, int w, int h)
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

	int Window::getWidth() const
	{
		return settings.resolution.width;
	}

	int Window::getHeight() const
	{
		return settings.resolution.height;
	}
	
	// Centers the given Blittable in the given Window.
	void Window::center(Blittable& b) const
	{
		b.setx(settings.resolution.width / 2 - b.getWidth() / 2);
		b.sety(settings.resolution.height / 2 - b.getHeight() / 2);
		
		return;
	}
	
	// Centers the given Blittable on the X-Axis in the given window.
	void Window::centerx(Blittable& b) const
	{
		b.setx(settings.resolution.width / 2 - b.getWidth() / 2);
		return;
	}
	
	// Centers the given Blittable on the Y-Axis in the given window.
	void Window::centery(Blittable& b) const
	{
		b.sety(settings.resolution.height / 2 - b.getHeight() / 2);
		return;
	}
	
	void Window::centerxco(Blittable& b, int x) const
	{
		b.setx(x - b.getWidth() / 2);
		return;
	}
	
	void Window::centeryco(Blittable& b, int y) const
	{
		b.sety(y - b.getHeight() / 2);
		return;
	}
	
	void Window::centerco(Blittable& b, int x, int y) const
	{
		centerxco(b, x);
		centeryco(b, y);
		return;
	}
	
	void Window::top(Blittable& b) const
	{
		b.sety(0);
		return;
	}
	
	void Window::bottom(Blittable& b) const
	{
		b.sety(settings.resolution.height - b.getHeight());
		return;
	}
	
	void Window::left(Blittable& b) const
	{
		b.setx(0);
		return;
	}
	
	void Window::right(Blittable& b) const
	{
		b.setx(settings.resolution.width - b.getWidth());
		return;
	}
	
	SDL_Renderer* Window::getRenderer() const
	{
		return renderer;
	}
	
	WindowSettings Window::getSettings() const
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
		
		if(settings.fullscreen)
		{
			window = SDL_CreateWindow(settings.title.c_str(),
									  SDL_WINDOWPOS_UNDEFINED,
									  SDL_WINDOWPOS_UNDEFINED,
									  settings.resolution.width,
									  settings.resolution.height,
									  SDL_WINDOW_FULLSCREEN);
		}
		else
		{
			window = SDL_CreateWindow(settings.title.c_str(),
									  SDL_WINDOWPOS_UNDEFINED,
									  SDL_WINDOWPOS_UNDEFINED,
									  settings.resolution.width,
									  settings.resolution.height,
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

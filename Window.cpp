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
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
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
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	}

	Window::Window(std::string title, int w, int h, bool fs)
	{
		width = w;
		height = h;
		if(fs)
			window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_FULLSCREEN);
		else
			window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
									  SDL_WINDOWPOS_UNDEFINED, w, h, 0);
		if(window == nullptr)
			std::cout << "SDL_Window creation failed.";
		else
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
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
	
	void Window::draw(Sprite& s)
	{
		// Don't draw if transparent. Waste of resources.
		if(s.getAlpha() == TRANSPARENT)
			return;
		SDL_Rect sdlr = s.getPosition();
		sdlr.w = s.getWidth();
		sdlr.h = s.getHeight();
		
		SDL_RenderCopy(renderer, s.getTexture(), s.getInputRect(), &sdlr);
		return;
	}
	
	void Window::draw(TileMap& m)
	{
		SDL_Rect info = m.getTileDimensions();
		int x_start = 0, y_start = 0; // Where to begin drawing the map.
		// If map is smaller than window, center it.
		if(info.w * m.getDimensions().w < width)
			x_start = (width / 2) - (info.w * m.getDimensions().w / 2);
		if(info.h * m.getDimensions().h)
			y_start = (height / 2) - (info.h * m.getDimensions().h / 2);
		
		for(int y = y_start; y < m.getTileDimensions().h * m.getDimensions().h + y_start; y += m.getTileDimensions().h)
		{
			for(int x = x_start; x < m.getTileDimensions().w * m.getDimensions().w + x_start; x += m.getTileDimensions().w)
			{
				info.x = x;
				info.y = y;
				SDL_RenderCopy(renderer, m.getTile((x - x_start) / m.getTileDimensions().w, (y - y_start) / m.getTileDimensions().h)->getTexture(), nullptr, &info);
			}
		}
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
		return width;
	}

	int Window::getHeight()
	{
		return height;
	}
	
	// Centers the given Blittable in the given Window.
	void Window::center(Blittable& b)
	{
		b.setx(width / 2 - b.getWidth() / 2);
		b.sety(height / 2 - b.getHeight() / 2);
		
		return;
	}
	
	// Centers the given Blittable on the X-Axis in the given window.
	void Window::centerx(Blittable& b)
	{
		b.setx(width / 2 - b.getWidth() / 2);
		return;
	}
	
	// Centers the given Blittable on the Y-Axis in the given window.
	void Window::centery(Blittable& b)
	{
		b.sety(height / 2 - b.getHeight() / 2);
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
		b.sety(height - b.getHeight());
		return;
	}
	
	void Window::left(Blittable& b)
	{
		b.setx(0);
		return;
	}
	
	void Window::right(Blittable& b)
	{
		b.setx(width - b.getWidth());
		return;
	}
	
	SDL_Renderer* Window::getRenderer()
	{
		return renderer;
	}
}

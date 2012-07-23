#include "Window.h"

namespace hm
{
	Window::Window()
	{
		screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
		resetClearColor();
	}

	Window::Window(int w, int h, int bpp)
	{
		screen = SDL_SetVideoMode(w, h, bpp, SDL_SWSURFACE);
		resetClearColor();
	}

	Window::Window(std::string title, int w, int h, int bpp)
	{
		screen = SDL_SetVideoMode(w, h, bpp, SDL_SWSURFACE);

		SDL_WM_SetCaption(title.c_str(), NULL);
		resetClearColor();
	}

	Window::~Window()
	{
		// Nothing to do here.
	}

    bool Window::getStatus()
    {
        return (screen != NULL);
    }

	void Window::draw(Blittable& b)
	{
		clear();
		SDL_BlitSurface(b.getSurface(), NULL, screen, b.getPosition());
		needRefresh = true;
		return;
	}

	void Window::draw(Sprite& s)
	{
		// Drawing for sprites is specially handled.
		clear();
		SDL_BlitSurface(s.getSurface(), s.getSpriteClip(), screen, s.getPosition());
		needRefresh = true; // Needs to be flipped.
		return;
	}
	
	void Window::clear()
	{
		// Don't clear the window if there are changes pending.
		if(!needRefresh)
			SDL_FillRect(screen, NULL, clearColor);
		return;
	}

	Uint32 Window::getClearColor()
	{
		return clearColor;
	}

	void Window::setClearColor(Uint32 clearColor)
	{
		this->clearColor = clearColor;
		return;
	}

	void Window::setClearColor(Uint8 red, Uint8 green, Uint8 blue)
	{
		clearColor = SDL_MapRGB(screen->format, red, green, blue);
		return;
	}

	void Window::resetClearColor()
	{
		// Sets the clearColor to black.
		clearColor = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
		return;
	}

	void Window::refresh()
	{

		if(needRefresh)
		{
			SDL_Flip(screen);
			needRefresh = false;
		}

		return;
	}

	// Centers the given Blittable in the given Window.
	void center(Blittable& b, Window& w)
	{
		b.getPosition()->x = w.screen->w / 2 - b.getSurface()->w / 2;
		b.getPosition()->y = w.screen->h / 2 - b.getSurface()->h / 2;

		return;
	}
}

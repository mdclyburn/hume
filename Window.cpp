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

    bool Window::getStatus()
    {
        return (screen != NULL);
    }

	void Window::draw(Image& i)
	{
		SDL_BlitSurface(i.getImage(), NULL, screen, i.getPosition());
		needRefresh = true; // Needs to be flipped.
		return;
	}

	void Window::draw(Sprite& s)
	{
		SDL_BlitSurface(s.getImage(), s.getSpriteClip(), screen, s.getPosition());
		needRefresh = true; // Needs to be flipped.
		return;
	}
	
	void Window::clear()
	{
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
		clearColor = SDL_MapRGB(screen->format, 0xFF, 0x00, 0xFF);
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
};

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

	void Window::draw(Image& i)
	{
		clear();
		SDL_BlitSurface(i.getImage(), NULL, screen, i.getPosition());
		needRefresh = true; // Needs to be flipped.
		return;
	}

	void Window::draw(Sprite& s)
	{
		clear();
		SDL_BlitSurface(s.getImage(), s.getSpriteClip(), screen, s.getPosition());
		needRefresh = true; // Needs to be flipped.
		return;
	}

	void Window::draw(Text &t)
    {
		clear();
		SDL_BlitSurface(t.getSurface(), NULL, screen, t.getPosition());
		needRefresh = true;

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
}

// Hume Library Version 0.6

#ifndef Window_H
#define Window_H

#include <string>
#include <iostream>

#include <SDL2/SDL.h>

#include "Blittable.h"
#include "WindowSettings.h"

namespace hm
{
	/*
	 Window based off of SDL_Window which has its own
	 renderer as well. Capable of normal windows as well
	 as fullscreen windows.
	 */
	class Window
	{
	public:
		Window();
		Window(const WindowSettings& ws);
		~Window();

		void setTitle(const std::string& title);
		bool getStatus() const;

		void draw(const Blittable& b);
		void draw(const Blittable& b, const int x, const int y);
		void draw(const Blittable& b, const int x, const int y, const int w, const int h);

		void clear();
		void forceRefresh();
		void refresh();

		int getWidth() const;
		int getHeight() const;
		
		void center(Blittable& b) const;
		void centerx(Blittable& b) const;
		void centery(Blittable& b) const;
		void centerxco(Blittable& b, int x) const;
		void centeryco(Blittable& b, int y) const;
		void centerco(Blittable& b, int x, int y) const;
		void top(Blittable& b) const;
		void bottom(Blittable& b) const;
		void left(Blittable& b) const;
		void right(Blittable& b) const;
		
		SDL_Renderer* getRenderer() const;
		WindowSettings getSettings() const;

	private:
		bool needRefresh;
		Uint32 clearColor;
		WindowSettings settings;
		SDL_Window* window;
		SDL_Renderer* renderer;
		
		void create();
	};
}

#endif

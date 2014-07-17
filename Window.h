/*
 Hume Library Version 0.4.3
 */

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
		Window(WindowSettings ws);
		~Window();

		void setTitle(std::string title);
		bool getStatus();

		void draw(Blittable& b);
		void draw(Blittable& b, int x, int y);
		void draw(Blittable& b, int x, int y, int w, int h);

		void clear();
		void forceRefresh();
		void refresh();

		int getWidth();
		int getHeight();
		
		void center(Blittable& b);
		void centerx(Blittable& b);
		void centery(Blittable& b);
		void centerxco(Blittable& b, int x);
		void centeryco(Blittable& b, int y);
		void centerco(Blittable& b, int x, int y);
		void top(Blittable& b);
		void bottom(Blittable& b);
		void left(Blittable& b);
		void right(Blittable& b);
		
		SDL_Renderer* getRenderer();
		WindowSettings getSettings();

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

// Hume Library Version 0.6

#ifndef WINDOWSETTINGS_H
#define WINDOWSETTINGS_H

#include <iostream>
#include <string>

#include <SDL2/SDL.h>

#include "Logger.h"

namespace hm
{
	// A given resolution.
	struct Resolution
	{
		unsigned int width;
		unsigned int height;
	};
	
	/*
	 Used by Window object to set the user's desired
	 options.
	 */
	struct WindowSettings
	{
		bool fullscreen;
		std::string title;
		Resolution resolution;

		WindowSettings();
		~WindowSettings();

		void setBestFullscreenMode();
	};
	
	std::ostream& operator<<(std::ostream& os, const WindowSettings& ws);
}

#endif

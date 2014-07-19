/*
 Hume Library Version 0.5
 */

#include "WindowSettings.h"

namespace hm
{
	WindowSettings::WindowSettings() : fullscreen(true), title("Hume Window")
	{
		setBestFullscreenMode();
	}
	
	WindowSettings::~WindowSettings()
	{
		
	}
	
	void WindowSettings::setBestFullscreenMode()
	{
		fullscreen = true;
		int display_mode_count = SDL_GetNumDisplayModes(0);
		if(display_mode_count < 1)
		{
			Logger::getLogger()->log("No available display modes.", ERROR);
			exit(0);
		}
		else
		{
			SDL_DisplayMode mode;
			int success;
			do
			{
				success = SDL_GetDisplayMode(0, 0, &mode);
			}
			while(success != 0);
			
			resolution.width = mode.w;
			resolution.height = mode.h;
			
			if(Logger::getLogger()->getLogLevel() >= LogLevel::INFO)
			{
				std::string msg = "Best fullscreen resolution: " +
				std::to_string(mode.w) + "x" +
				std::to_string(mode.h) + ".";
				Logger::getLogger()->log(msg);
			}
		}
	}
	
	std::ostream& operator<<(std::ostream& os, const WindowSettings& ws)
	{
		// Window title
		os << "Title: " << ws.title << std::endl;
		
		// Resolution
		os << "Resolution: "
		<< std::to_string(ws.resolution.width)
		<< "x" << std::to_string(ws.resolution.height) << std::endl;
		
		// Fullscreen?
		os << "Fullscreen: ";
		if(ws.fullscreen)
			os << "yes";
		else
			os << "no";
		os << std::endl;
		
		return os;
	}
}

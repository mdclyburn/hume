//
//  WindowSettings.cpp
//  Hume
//
//  Created by Marshall Clyburn on 7/11/14.
//  Copyright (c) 2014 Marshall Clyburn. All rights reserved.
//

#include "WindowSettings.h"

namespace hm
{
	/*
	 Default to a fullscreen window at the maximum
	 resolution supported by the attached screen.
	 */
	WindowSettings::WindowSettings() : fullscreen(true), title("Hume Window")
	{
		setBestFullscreenMode();
	}
	
	WindowSettings::~WindowSettings()
	{
		
	}
	
	/*
	 Set the window to fullscreen at the best possible
	 resolution attainable.
	*/
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
			
			if(Logger::getLogger()->getLogLevel() >= LogLevel::INFO)
			{
				std::string msg = "Using resolution of " +
				std::to_string(mode.w) + "x" +
				std::to_string(mode.h) + ".";
				Logger::getLogger()->log(msg);
			}
		}
	}
}

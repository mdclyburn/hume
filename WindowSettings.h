//
//  WindowSettings.h
//  Hume
//
//  Created by Marshall Clyburn on 7/11/14.
//  Copyright (c) 2014 Marshall Clyburn. All rights reserved.
//

#ifndef WINDOWSETTINGS_H
#define WINDOWSETTINGS_H

#include <iostream>
#include <string>

#include <SDL2/SDL.h>

#include "Logger.h"

namespace hm
{
	struct Resolution
	{
		unsigned int width;
		unsigned int height;
	};
	
	/*
	 Used by Window object to set the user's desired
	 options.
	 */
	class WindowSettings
	{
	public:
		WindowSettings();
		~WindowSettings();
		
		void useFullscreen(bool b)
		{ fullscreen = b; return; }
		void setTitle(std::string title)
		{ this->title = title; return; }
		void setResolution(Resolution r)
		{ resolution = r; return; }
		
		bool isFullscreen()
		{ return fullscreen; }
		std::string getTitle()
		{ return title; }
		Resolution getResolution()
		{ return resolution; }
		
		void setBestFullscreenMode();
		
	protected:
		bool fullscreen;
		std::string title;
		
		Resolution resolution;
	};
}

#endif

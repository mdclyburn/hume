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
		
		void setBestFullscreenMode();
		
	protected:
		bool fullscreen;
		
		Resolution resolution;
	};
}

#endif

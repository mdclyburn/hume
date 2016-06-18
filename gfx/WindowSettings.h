/*
  Hume Library
  nCopyright (C) 2015 Marshall Clyburn

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
  USA
*/

#ifndef WINDOWSETTINGS_H
#define WINDOWSETTINGS_H

#include <cassert>
#include <string>

#include <SDL2/SDL.h>

namespace hume
{
    /** Parameters for Window.
	 *
	 * Settings that can be applied to a Window.
	 */
	struct WindowSettings
	{
		/** Whether or not to use a full screen mode. */
		bool fullscreen;

		/** The text to be displayed in the title bar of the window. */
		std::string title;

		/** The width of the window. */
		unsigned int width;

		/** The height of the window */
		unsigned int height;

		/** The default constructor.
		 *
		 * Defaults to a non-full screen window of size 800x450 with the title 'Hume Window'.
		 */
		WindowSettings();
	};

/** Set the best possible full screen mode.
 *
 * Will set the parameters to the highest possible full screen
 * mode.
 *
 * \param settings the WindowSettings struct to fill
 */
	void set_best_fullscreen_mode(WindowSettings& settings);
}

#endif

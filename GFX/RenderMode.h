/*
  Hume Library
  Copyright (C) 2015 Marshall Clyburn

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

#ifndef RENDERMODE_H
#define RENDERMODE_H

namespace hume
{
    /** Text rendering mode.
     *
     * RenderMode has a one-to-one correspondence to the different ways SDL2 TTF can
     * render text.
     */
    enum class RenderMode
    {
        /** Quick and Dirty
	 *
	 * Create an 8-bit palettized surface and renders the given text at fast
	 * quality with the given font and color.
         */
        Solid,

        /** Slow and Nice, but with a Solid Box
	 *
	 * Create an 8-bit palettized surface and render the given text at high
	 * quality with the given font and colors.
         */
        Shaded,

        /** Slow Slow Slow, but Ultra Nice over another image
	 *
	 * Create a 32-bit ARGB surface and render the given text at high quality using alpha
	 * blending to dither the font with the given color. Results in a surface with alpha
	 * transparency so you don't have a solid colored box around the text.
         */
        Blended
    };
}

#endif

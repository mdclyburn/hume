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
     * RenderMode has a one-to-one correspondence to the different ways SDL2_ttf can
     * render text.
     */
    enum class RenderMode
    {
        /** 'Quick and Dirty'
         *
         * From SDL2_ttf documentation: 'Creates an 8-bit palettized surface and renders
         * the given text at fast quality with the given font and color'. Solid
         * takes the least amount of time to render and blit, but the text does not come
         * out smooth.
         */
        Solid,

        /** 'Slow and Nice, but with a Solid Box'
         *
         * From SDL2_ttf documentation: 'Creates an 8-bit palettized surface and renders
         * the given text at high quality with the given font and colors'. Shaded
         * renders faster than Blended, but slower than Solid. Blitting a Shaded texture
         * is as fast as blitting a Solid once it is rendered. The resulting text will
         * have a box around it, though.
         */
        Shaded,

        /** 'Slow Slow Slow, but Ultra Nice over another image'
         *
         * From SDL2_ttf documentation: 'Creates a 32-bit ARGB surface and renders the
         * given text at high quality with the given font and colors'. Blended text renders
         * slower than Solid, but is about as fast as Shaded. The texture will blit slower
         * than the other two rendering modes though.
         */
        Blended
    };
}

#endif

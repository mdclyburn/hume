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

#ifndef PROPERTIES_H
#define PROPERTIES_H

namespace hume
{
    /** Drawing parameters for Blittables.
     *
     * Provides options for Blittables that are to be drawn to the screen. The 'x', 'y',
     * 'w', and 'h' fields correspond to positioning and size. The 's*' properties specify
     * a specific portion of the Blittable.
     */
    struct Properties
    {
        /** The x-coordinate.
         *
         * The x-coordinate that will be used as the starting point when drawing the
         * Blittable to the screen.
         */
        int x;

        /** The y-coordinate.
         *
         * The y-coordinate that will be used as the starting point when drawing the
         * Blittable to the screen.
         */
        int y;

        /** The width.
         *
         * The width that the Blittable will be drawn with. Any width specified greater
         * than the Blittable's native width will result in the stretching of the
         * appearance.
         */
        unsigned int w;

        /** The height.
         *
         * The height that the Blittable will be drawn with. Any height specified greater
         * than the Blittable's native height will result in the stretching of the
         * appearance.
         */
        unsigned int h;

        /** The source x-coordinate.
         *
         * The x-coordinate of the portion of the Blittable texture to be drawn.
         */
        unsigned int sx;

        /** The source y-coordinate.
         *
         * The y-coordinate of the portion of the Blittable texture to be drawn.
         */
        unsigned int sy;

        /** The source width.
         *
         * The width of the portion of the Blittable texture to be drawn.
         */
        unsigned int sw;

        /** The source height.
         *
         * The height of the portion of the Blittable texture to be drawn.
         */
        unsigned int sh;

        /** The default constructor.
         *
         * Constructs a Properties struct.
         */
        Properties();

        /** The constructor allowing specification.
         *
         * Constructs a Properties struct with the desired fields.
         *
         * \param x the x-coordinate
         * \param y the y-coordinate
         * \param w the width
         * \param h the height
         * \param sx the source x-coordinate
         * \param sy the source y-coordinate
         * \param sw the source width
         * \param sh the source height
         */
        Properties(const int x,
                   const int y,
                   const unsigned int w,
                   const unsigned int h,
                   const unsigned int sx,
                   const unsigned int sy,
                   const unsigned int sw,
                   const unsigned int sh);
    };
}

#endif

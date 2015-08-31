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

#ifndef properties_h
#define properties_h

/*
Provides options for Blittable that are to be drawn to
the screen.

x: x coordinate
y: y coordinate
w: width
h: height

sx: x coordinate of source in Blittable
sy: y coordinate of source in Blittable
sw: width of source in Blittable
sh: height of source in Blittable

A width or height of zero will cause the Blittable to be drawn
using its native size.

The s- variables allow for a specific portion of the Blittable to be
drawn. A value of zero in the 'sw' OR 'sh' fields will cause the
entire Blittable to be drawn.
*/

struct Properties
{
    unsigned int x;
    unsigned int y;
    unsigned int w;
    unsigned int h;

    unsigned int sx;
    unsigned int sy;
    unsigned int sw;
    unsigned int sh;

    Properties() : x(0), y(0), w(0), h(0) {}
    Properties(const unsigned int x,
	       const unsigned int y,
	       const unsigned int w,
	       const unsigned int h,
	       const unsigned int sx,
	       const unsigned int sy,
	       const unsigned int sw,
	       const unsigned int sh) : x(x), y(y), w(w), h(h), sx(sx), sy(sy), sw(sw), sh(sh) {}
};

#endif

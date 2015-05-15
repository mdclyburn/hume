// Hume Library Version 0.7

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

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

A width or height of zero will cause the Blittable to be drawn
using its native size.
*/

struct Properties
{
    unsigned int x;
    unsigned int y;
    unsigned int w;
    unsigned int h;

    Properties() : x(0), y(0), w(0), h(0) {}
    Properties(const unsigned int x,
	       const unsigned int y,
	       const unsigned int w,
	       const unsigned int h) : x(x), y(y), w(w), h(h) {}
};

#endif

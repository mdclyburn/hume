// Hume Library Version 0.7

#ifndef properties_h
#define properties_h

struct Properties
{
    unsigned int x;
    unsigned int y;

    Properties() : x(0), y(0) {}
    Properties(const unsigned int x,
	       const unsigned int y) : x(x), y(y) {}
};

#endif

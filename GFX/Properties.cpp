#include "Properties.h"

namespace hume
{
	Properties::Properties() : x(0), y(0), w(0), h(0), sx(0), sy(0), sw(0), sh(0)
	{
	}

	Properties::Properties(const int x, const int y, const unsigned int w, const unsigned int h, const unsigned int sx, const unsigned int sy, const unsigned int sw, const unsigned int sh) : x(x), y(y), w(w), h(h), sx(sx), sy(sy), sw(sw), sh(sh)
	{
	}
}

#ifndef SDLEXCEPTION_H
#define SDLEXCEPTION_H

#include <SDL2/SDL.h>

#include "Exception.h"

class SDLException : public Exception
{
public:
	SDLException();
	virtual ~SDLException();
};

#endif

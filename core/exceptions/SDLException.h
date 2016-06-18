#ifndef SDLEXCEPTION_H
#define SDLEXCEPTION_H

#include <SDL2/SDL.h>

#include "Exception.h"

class SDLException : public Exception
{
public:
	SDLException();
	SDLException(const std::string& message);
	virtual ~SDLException();
};

#endif

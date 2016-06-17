#include "SDLException.h"

SDLException::SDLException() : Exception("SDL2 has encountered an error:\n")
{
	message.append(SDL_GetError());
}

SDLException::~SDLException()
{
}

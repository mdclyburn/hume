#include "SDLTTFException.h"

SDLTTFException::SDLTTFException() : Exception("SDL_ttf has encountered an error: ")
{
	message.append(TTF_GetError());
}

SDLTTFException::SDLTTFException(const std::string& message) : Exception(message)
{
}

SDLTTFException::~SDLTTFException()
{
}

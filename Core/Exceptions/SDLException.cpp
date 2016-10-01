#include "SDLException.h"

namespace hume
{
    SDLException::SDLException() : Exception("SDL2 has encountered an error: ")
    {
        message.append(SDL_GetError());
    }

    SDLException::SDLException(const std::string& message) : Exception(message)
    {
    }

    SDLException::~SDLException()
    {
    }
}

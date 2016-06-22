#ifndef SDLTTFEXCEPTION_H
#define SDLTTFEXCEPTION_H

#include <SDL2/SDL_ttf.h>

#include "core/exceptions/Exception.h"

namespace hume
{
	class SDLTTFException : public Exception
	{
	public:
		SDLTTFException();
		SDLTTFException(const std::string& message);
		virtual ~SDLTTFException();
	};
}

#endif

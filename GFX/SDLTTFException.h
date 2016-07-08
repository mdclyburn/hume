#ifndef SDLTTFEXCEPTION_H
#define SDLTTFEXCEPTION_H

#include <SDL2/SDL_ttf.h>

#include "Core/Exceptions/Exception.h"

namespace hume
{
	class SDLTTFException : public Exception
	{
	public:
		SDLTTFException();
		explicit SDLTTFException(const std::string& message);
		virtual ~SDLTTFException();
	};
}

#endif

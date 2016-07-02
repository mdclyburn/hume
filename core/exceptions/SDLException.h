#ifndef SDLEXCEPTION_H
#define SDLEXCEPTION_H

#include <SDL2/SDL.h>

#include "Exception.h"

namespace hume
{
	class SDLException : public Exception
	{
	public:
		SDLException();
		explicit SDLException(const std::string& message);
		virtual ~SDLException();
	};
}

#endif

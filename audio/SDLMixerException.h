#ifndef SDLMIXEREXCEPTION_H
#define SDLMIXEREXCEPTION_H

#include <SDL2/SDL_mixer.h>

#include "core/exceptions/Exception.h"

namespace hume
{
	class SDLMixerException : public Exception
	{
	public:
		SDLMixerException();
		explicit SDLMixerException(const std::string& message);
		virtual ~SDLMixerException();
	};
}

#endif

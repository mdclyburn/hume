#ifndef SDLMIXEREXCEPTION_H
#define SDLMIXEREXCEPTION_H

#include <SDL2/SDL_mixer.h>

#include "Exception.h"

class SDLMixerException : public Exception
{
public:
	SDLMixerException();
	SDLMixerException(const std::string& message);
	virtual ~SDLMixerException();
};

#endif

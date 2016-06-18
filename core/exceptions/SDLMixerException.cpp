#include "SDLMixerException.h"

SDLMixerException::SDLMixerException() : Exception("SDL2_mixer has encountered an error:\n")
{
	message.append(Mix_GetError());
}

SDLMixerException::SDLMixerException(const std::string& message) : Exception(message)
{
}

SDLMixerException::~SDLMixerException()
{
}

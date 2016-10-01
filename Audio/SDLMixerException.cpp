#include "SDLMixerException.h"

namespace hume
{
    SDLMixerException::SDLMixerException() : Exception("SDL2_mixer has encountered an error: ")
    {
        message.append(Mix_GetError());
    }

    SDLMixerException::SDLMixerException(const std::string& message) : Exception(message)
    {
    }

    SDLMixerException::~SDLMixerException()
    {
    }
}

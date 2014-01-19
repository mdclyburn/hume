/*
 * Sound.h
 *
 *  Created on: Nov 17, 2012
 *      Author: Marshall
 */

#ifndef SOUND_H
#define SOUND_H

#include <string>
#include <iostream>

#include <SDL2_mixer/SDL_mixer.h>

namespace hm
{
	/*
	 * Defines a basic audio chunk.
	 * Supports WAV files only.
	 */
	class Sound
	{
		public:
			Sound(); // Basic constructor.
			Sound(std::string file); // Performs basic constructor tasks and loads file.
			~Sound(); // Destructor.

			void play(); // Plays the sound.

			bool open(std::string file); // Loads a sound from a file.
			void close(); // Closes the sound file.
			void setVolume(int volume); // Sets the volume of the sound. Valid values: 0 - 100
		private:
			Mix_Chunk* sound; // The sound object.
	};
}

#endif /* SOUND_H_ */

/*
  Hume Library
  Copyright (C) 2015 Marshall Clyburn

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
  USA
*/

#ifndef SOUND_H
#define SOUND_H

#include "Audio.h"
#include "SDLMixerException.h"

namespace hume
{
    /** Sound to be played that is short in length.
	 *
	 * The Sound class is for audio files that are considered to be special effects or 'SFX'.
	 */
	class Sound : public Audio
	{
	public:

		/** The default constructor.
		 *
		 * Constructs a Sound object.
		 */
		Sound();

		/** The destructor.
		 *
		 * If a file is currently loaded, it is released.
		 */
		virtual ~Sound();

		/** Open an audio chunk.
		 *
		 * Loads audio from file. Calling this function when an audio chunk is already loaded
		 * will likely result in a memory leak.
		 *
		 * \param file_name the path to the audio chunk file
		 */
		void open(const std::string& file_name);

		/** Close an audio chunk.
		 *
		 * Unloads the audio chunk from memory, freeing its resources. Calling this function when no
		 * audio chunk is loaded will result in undefined behavior.
		 */
		void close();

		/** Play the audio chunk.
		 *
		 * Play the audio chunk once. Calling this function when no audio chunk is loaded will result
		 * in the program aborting.
		 */
		void play();

		/** Returns the underlying Mix_Chunk.
		 *
		 * Returns a pointer to the underlying SDL2 Mix_Chunk.
		 */
		Mix_Chunk* get_sound() const;

	protected:

		/** The underlying Mix_Chunk. */
		Mix_Chunk* chunk;
	};
}

#endif

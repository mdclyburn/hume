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

#ifndef AUDIO_H
#define AUDIO_H

#include <cassert>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

/** Abstract class for audio files.
 *
 * Defines some common properties of sound files.
 */
class Audio
{
public:

	/** The default constructor.
	 *
	 * Sets the volume the audio is to played at to max (100%)
	 */
    Audio();

	/** The destructor.
	 *
	 */
    virtual ~Audio();

	/** Open a file.
	 *
	 * Derived classes should use this function to load a file.
	 *
	 * \param file_name the path to the file
	 */
    virtual void open(const std::string& file_name) = 0;

	/** Close a file.
	 *
	 * Derived classes should use this function to close a file, releasing resources.
	 */
    virtual void close() = 0;

	/** Play loaded audio.
	 *
	 * Derived classes should use this function to play audio.
	 */
    virtual void play() = 0;

protected:
};

#endif

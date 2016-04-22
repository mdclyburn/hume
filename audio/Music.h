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

#ifndef MUSIC_H
#define MUSIC_H

#include "Audio.h"

/** Sound to be played over a longer length of time.
 *
 * The Music class is for audio files that are sufficienly long enough to not be considered
 * 'sound effects' (SFX). Music has the ability to loop, play, pause, and stop, as well as
 * even fade in.
 */
class Music : public Audio
{
public:

	/** The default constructor.
	 *
	 * Constructs a Music object. Sets the fade-in length to zero.
	 */
    Music();

	/** The destructor.
	 *
	 * This destructor does not automatically release resources. They must be released
	 * manually.
	 */
    virtual ~Music();

	/** Open a music file.
	 *
	 * Loads a music file into memory given its path. Before this function will work properly, the
	 * SDL audio subsystem must be initialized, and the SDL_mixer must be initialized with support
	 * for the appropriate formats. This function will not close an audio file if it is already
	 * loaded, resulting in a memory leak if it is called in such a situation.
	 *
	 * \param file_name the path to the file.
	 */
    void open(const std::string& file_name);

	/** Close the music file.
	 *
	 * Releases the memory associated with the audio file. A failure to open the file will result
	 * in the program crashing. Calling this function when music is not loaded will result in
	 * undefined behavior.
	 */
    void close();

	/** Play music.
	 *
	 * This function is equivalent to calling Music::play(const unsigned int loops) with zero
	 * loops. The audio will play through exactly one time. Calling this function when
	 * no music has been loaded will result in undefined behavior. See
	 * Music::play(const unsigned int loops).
	 */
    void play();

	/** Play the music a specified number of times.
	 *
	 * This function will play the audio file, looping it the specified number of times. The
	 * specified fade-in time (set beforehand) is used. Calling this function when no music has been
	 * loaded will result in undefined behavior.
	 *
	 * \param loops the number of times to play the music after it finishes (play count = 1 + loops)
	 */
    void play(const unsigned int loops);

	/** Pause the music.
	 *
	 * Stops the music with the implication that a call to Music::resume() will follow, causing the
	 * audio to play from where it was paused. Calling this function when no music is loaded or when
	 * the music is already paused will result in undefined behavior.
	 */
    void pause();

	/** Resume playing music.
	 *
	 * Restart the music from the point at which Music::pause() was called. Calling this function
	 * when no music is loaded, or when the music is already playing will result in undefined
	 * behavior.
	 */
    void resume();

	/** Stop playing music.
	 *
	 * The functional opposite of Music::play(). Stops the music.
	 */
    void stop();

	/** Set the fade-in time.
	 *
	 * Sets the amount of time that should be spent fading the music in from 0% to current volume when
	 * playing. This is only used when music is first played with a call to Music::play().
	 *
	 * \param ms the amount of time in milliseconds
	 */
    void set_fade_in(const unsigned int ms);

	/** Sets the volume of the music.
	 *
	 * Sets auditory level the music plays at. This value is translated from a scale from 0 to 100 to
	 * a scale from 0 to 128. While some specificity of volume levels is lost in the process, it is
	 * much simpler to remember the maximum value. This changes the volume for all music, not just
	 * a single instance. Setting this value above 100 will result in undefined behavior.
	 *
	 * \param v the new volume level, a value from 0 to 100
	 */
    void set_volume(const unsigned int v);

protected:

	/** The time in ms to spend fading in the music. */
    unsigned int fade_in;

	/** The underlying Mix_Music object. */
    Mix_Music* music;
};

#endif

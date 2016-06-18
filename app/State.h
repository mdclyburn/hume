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

#ifndef STATE_H
#define STATE_H

#include "SDL2/SDL.h"

namespace hume
{
    /** An applications state.
	 *
	 * A State represents a single 'mode' of execution, whether it be some sort
	 * of menu, 'Now Playing' screen, title screen, etc... They are to be used in
	 * conjunction with the Application state stack. Most of the functions will
	 * need a derived implementation.
	 */ 
	class State
	{
	public:

		/** The default constructor.
		 *
		 * Constructs a State.
		 */
		State();

		/** The destructor.
		 *
		 */
		virtual ~State();

		/** Suspends the State.
		 *
		 * Releases resource and possibly performs some temporary cleanup. This function
		 * is called on a running state before it is paused to allow a new State to run.
		 */
		virtual void pause() = 0;

		/** Reinitializes the State from a paused state.
		 *
		 * Reacquires resources and initializes the state to prepare it to run again
		 * as it was before the call to State::pause() was made.
		 */
		virtual void resume() = 0;

		/** Performs initialization.
		 *
		 * Initializes a state so that it may process input, update, and display. This function
		 * should perform more initialization than a typical call to State::resume();
		 */
		virtual void initialize() = 0;

		/** Performs cleanup.
		 *
		 * Prepares the State to be completely stopped. This function should perform more
		 * cleanup than a typical call to State::pause();
		 */
		virtual void shutdown() = 0;

		/** Process input.
		 *
		 * Handle input from the user.
		 *
		 * \param e SDL_Event struct containing input information
		 */
		virtual void process_input(const SDL_Event& e) = 0;

		/** Update internals.
		 *
		 * Update State internals.
		 */
		virtual void update() = 0;

		/** Update Window content.
		 *
		 * Draws entities to be displayed with a call to Window::refresh().
		 */
		virtual void display() = 0;
	};
}

#endif

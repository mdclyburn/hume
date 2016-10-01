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

#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>

namespace hume
{
    /** A timer with microsecond resolution.
     *
     * Makes use of the SDL_GetTicks() function to discern the amount of time
     * that has passed. The Timer has the ability to pause, unpause, and reset
     * itself.
     */
    class Timer
    {
    public:

        /** The default constructor.
         *
         * Constructs a paused timer that has not begun counting time.
         */
        Timer();

        /** The destructor.
         */
        virtual ~Timer();

        /** Starts the timer.
         *
         * Begins counting the number of microseconds that have passed since
         * the invocation of this function. Calling this function on any timer
         * that was already running or was paused will have the same effect as
         * calling reset, and then this function. The timer will begin counting
         * up from 0.000s.
         */
        void start();

        /** Pauses the timer.
         *
         * Stops the counter from counting up, but does not affect the current
         * value so that the current amount of time counted can be retrieved.
         */
        void pause();

        /** Resumes the timer.
         *
         * Begins the counter again if it was in the paused state. Invoking this
         * function on a timer that is not paused will have no effect on the
         * Timer whatsoever; nothing will occur.
         */
        void unpause();

        /** Clears the timer.
         *
         * Effectively stops the timer from counting up and resets the internal
         * counter to 0.000s. The timer will not begin timing after a call to this
         * function.
         */
        void reset();

        /** Returns counted time.
         *
         * Returns the amount of time that has passed while the timer is running. If
         * the timer is paused, it will return the amount of time it counted while
         * it was not paused. If the timer is not running and it is not paused (meaning
         * that it has not been run, or has been reset), this function will return
         * 0 (0.000s).
         */
        uint32_t get_elapsed_time() const;

        /** Tells if the timer is running.
         *
         * This function returns true if the timer is running, and false if it is
         * not (it is paused or has been reset).
         */
        bool is_running() const;

        /** Tells if the timer is paused.
         *
         * This function returns true if the timer is paused, and false if it is
         * not (i.e. it is actively running, newly created, or reset). Note that
         * a false value does not indicate that the timer is actively running.
         * To test if a timer is running, use the Timer::is_running().
         */
        bool is_paused() const;

    protected:
        bool running;
        bool paused;
        uint32_t start_time;
        uint32_t pause_time;
    };
}

#endif

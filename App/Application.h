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

#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>

#include <SDL2/SDL.h>

#include "Core/Timer.h"
#include "State.h"

namespace hume
{
    /** Example program framework.
     *
     * The Application class is designed to provide a starting point for developing complete
     * programs for Hume. The class only provides some suggestions in terms of design, and is
     * not meant to rigorously enforce a single method. It is not even required to make use
     * of Hume.
     */
    class Application
    {
    public:

        /** The default constructor.
         *
         * Limits the frame rate to 30 frames per second.
         */
        Application();

        /** The destructor.
         *
         */
        virtual ~Application();

        /** Starts application logic.
         *
         * This function is intended to allow a single call to Application to start running the
         * program. This would include handling initialization as well.
         */
        virtual void run() = 0;

        /** Signals the program to stop.
         *
         * Internally signals the application's main loop to stop running. Calling this function on
         * when the Application is not running has no adverse effects.
         */
        void stop();

        /** Sets the frame limit.
         *
         * Sets the maximum number of times to completely refresh the display. Setting this to zero will
         * result in undefined behavior.
         *
         * \param frame_rate the new frame limit
         */
        void set_frame_limit(const unsigned int frame_rate);

    protected:

        /** Initialize internals.
         *
         * This function should be overridden in derived classes. Performs initialization that will
         * allow the Application to reach a state where calling Application::run() would be viable.
         * The Application implementation initailizes SDL2.
         */
        virtual void initialize();

        /** Clean up internals.
         *
         * This function should be overridden in derived classes. Performs cleanup, freeing resources
         * and reversing work done by Application::initialize().
         */
        virtual void shutdown();

        /** Run the main loop.
         *
         * Runs the main loop of the program as long as Application::stop() is not called and
         * Application::running is true. The following three functions are called in the order listed:
         * Application::process_input(), Application::update(), and Application::display().
         */
        virtual void loop();

        /** Catch user input.
         *
         * This function should be overridden in derived classes. Processes user input.
         */
        virtual void process_input() = 0;

        /** Update internal data.
         *
         * This function should be overridden in derived classes. Updates internal application data.
         */
        virtual void update() = 0;

        /** Refresh the contents of the screen.
         *
         * This function should be overridden in derived classes. Displays what's been drawn to the
         * screen since the last frame was shown.
         */
        virtual void display() = 0;

        /** Add a state to the top of the stack.
         *
         * Directs the currently running state to suspend itself before initializing the new state
         * and placing it on the top of the stack.
         *
         * \param s the new State
         */
        virtual void push(State* const s);

        /** Remove the top state from the stack.
         *
         * Directs the currently running state to stop itself and clean up before being removed. The
         * state below it is then directed to resume running.
         */
        virtual State* pop();

        /** Controls whether the main loop should be running. */
        bool running;

        /** The calculated maximum amount of time processing a frame should take. */
        float frame_time;

        /** The State stack. */
        std::vector<State*> state_stack;
    };
}

#endif

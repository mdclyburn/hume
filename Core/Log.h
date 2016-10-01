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

#ifndef LOG_H
#define LOG_H

#include <string>

#include "Component.h"
#include "LogMode.h"

namespace hume
{
    /** Component for creating a logging system.
     *
     * An abstract logging class providing a number
     * of 'modes' in which to run it. This class is abstract
     * and will need to be inherited from to use.
     */
    class Log : public Component
    {
    public:

        /** Default constructor.
         *
         * The logging mode is set to default.
         */
        Log();

        /** Destructor.
         *
         */
        virtual ~Log();

        /** Write a message to the log.
         *
         * Write out a message to whatever medium the derived
         * class dictates.
         *
         * \param msg the message to be logged
         */
        virtual void log(const std::string& msg) = 0;

        /** Change the logging mode.
         *
         * Set the logging mode for the logger.
         *
         * \param l the logging mode to use
         */
        void set_mode(const LogMode l);

        /** Retrieve the current logging mode.
         *
         * Returns the logging mode that is currently in use.
         */
        LogMode get_mode() const;

    protected:

        /** Defines the behavior of logging.
         *
         * Depending on the value, the logger can use different
         * methods to log.
         */
        LogMode mode;
    };
}

#endif

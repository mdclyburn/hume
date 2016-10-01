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

#ifndef logmode_h
#define logmode_h

// ===== Logging Modes
// SILENT  - no output will be generated
// DEFAULT - the default logging mode
// FLUSHED - all log entries are immediately written out
// =====

/** Possible modes a Log can run in.
 *
 * A LogMode is designed to impose a specific behavior on the Log
 * it is assigned to. Those behaviors are defined below. It is worth noting
 * that since the Log class can only be subclassed, and not directly used,
 * any derived implementations may not follow the described behaviors if
 * they are not designed to do so. The handling of the value of LogMode is
 * at the user's discretion.
 */
enum class LogMode
{
    SILENT,  /**< The Log should not generate output. */
    DEFAULT, /**< The Log should behave as is expected during normal runs. */
    FLUSHED  /**< The Log should ensure every message sent to it makes it to output (screen, file, etc...). */
};

#endif

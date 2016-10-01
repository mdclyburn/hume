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

#ifndef COMPONENT_H
#define COMPONENT_H

namespace hume
{
    /** Abstract class for subsystems.
     *
     * The Component is the building block for other classes
     * in the Hume library. It represents a major (for lack
     * of a better word) component that can be initialized
     * and shutdown, its only two member functions, ignoring
     * the constructor and destructor.
     */
    class Component
    {
    public:
        Component();
        virtual ~Component();

        /** Perform initialization.
         *
         * Depending on the derived class, the behavior of this
         * function differs. The purpose of the initialize function
         * is to get the Component into a usable state. Because this
         * function does not return anything, the derived object must
         * have another method of indicating success, failure, etc.
         */
        virtual void initialize() = 0;
        virtual void shutdown() = 0;
    };
}

#endif

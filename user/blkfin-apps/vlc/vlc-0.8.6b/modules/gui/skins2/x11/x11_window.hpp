/*****************************************************************************
 * x11_window.hpp
 *****************************************************************************
 * Copyright (C) 2003 the VideoLAN team
 * $Id: x11_window.hpp 14187 2006-02-07 16:37:40Z courmisch $
 *
 * Authors: Cyril Deguet     <asmax@via.ecp.fr>
 *          Olivier Teulière <ipkiss@via.ecp.fr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef X11_WINDOW_HPP
#define X11_WINDOW_HPP

#include <X11/Xlib.h>

#include "../src/os_window.hpp"

class X11Display;
class X11DragDrop;


/// X11 implementation of OSWindow
class X11Window: public OSWindow
{
    public:
        X11Window( intf_thread_t *pIntf, GenericWindow &rWindow,
                   X11Display &rDisplay, bool dragDrop, bool playOnDrop,
                   X11Window *pParentWindow );

        virtual ~X11Window();

        // Show the window
        virtual void show( int left, int top ) const;

        // Hide the window
        virtual void hide() const;

        /// Move the window
        virtual void moveResize( int left, int top,
                                 int width, int height ) const;

        /// Bring the window on top
        virtual void raise() const;

        /// Set the opacity of the window (0 = transparent, 255 = opaque)
        virtual void setOpacity( uint8_t value ) const;

        /// Toggle the window on top
        virtual void toggleOnTop( bool onTop ) const;

        /// Get the window ID
        Window getDrawable() const { return m_wnd; }

    private:
        /// X11 display
        X11Display &m_rDisplay;
        /// Window ID
        Window m_wnd;
        /// Parent window
        X11Window *m_pParent;
        /// Indicates whether the window handles drag&drop events
        bool m_dragDrop;
        /// Drop target
        X11DragDrop *m_pDropTarget;
};


#endif

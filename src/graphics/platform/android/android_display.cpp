/*
 * Copyright © 2012 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Kevin DuBois <kevin.dubois@canonical.com>
 */

#include "mir/graphics/android/android_display.h"
#include "mir/geometry/rectangle.h"

#include <stdexcept>
namespace mg=mir::graphics;
namespace geom=mir::geometry;

mg::AndroidDisplay::AndroidDisplay()
{
    EGLint major, minor;

    egl_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (egl_display == EGL_NO_DISPLAY)
    {
        throw std::runtime_error("eglGetDisplay failed\n");
    }
    
    if (eglInitialize(egl_display, &major, &minor) == EGL_FALSE)
    {
        throw std::runtime_error("eglInitialize failure\n");
    }
    /* todo: we could adapt to different versions. */
    if ((major != 1) || (minor != 4))
    {
        throw std::runtime_error("must have EGL 1.4\n");
    }
   
    const EGLint attr [] =
    {
        EGL_NONE
    };
    EGLConfig egl_config;
    EGLint num_match_configs; 
    eglChooseConfig(egl_display, attr, &egl_config, 1, &num_match_configs ); 

}
    
geom::Rectangle mg::AndroidDisplay::view_area()
{
    geom::Rectangle rect;
    return rect;
}

void mg::AndroidDisplay::notify_update()
{

}

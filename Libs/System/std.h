/*****************************************************

      std.h - ANSI-C++ library: std
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               
                  Do not modify!
 *****************************************************/

// This may look like C code, but it is really -*- C++ -*-
/* 
Copyright (C) 1988, 1992 Free Software Foundation
    written by Doug Lea (dl@rocky.oswego.edu)

This file is part of the GNU C++ Library.  This library is free
software; you can redistribute it and/or modify it under the terms of
the GNU Library General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your
option) any later version.  This library is distributed in the hope
that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the GNU Library General Public License for more details.
You should have received a copy of the GNU Library General Public
License along with this library; if not, write to the Free Software
Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#ifndef _std_h
#define _std_h 1

#include <Gconfig.h>
#include <ccstddef.h>
#include <cstdlib.h>
#include <ccstring.h>
/*#include <unistd.h>*/
#include <cstdio.h> 
#include <cerrno.h>
/*#include <fcntl.h> */

extern "C" {
int strcasecmp _G_ARGS((const char*_LIBDEF_FAR_CPP_PTR, const char*_LIBDEF_FAR_CPP_PTR));
}

#endif 

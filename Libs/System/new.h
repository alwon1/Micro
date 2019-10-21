/*****************************************************

     new.h - ANSI-C++ library: new/delete
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               
                  Do not modify!
 *****************************************************/

// The -*- C++ -*- dynamic memory management header.
// Copyright (C) 1994 Free Software Foundation

#ifndef __NEW__
#define __NEW__

#ifdef __GNUG__
#pragma interface "std/new.h"
#endif

#include <cstddef.h>

extern "C++" {
typedef void (*new_handler)();
extern "C" new_handler set_new_handler (new_handler);

#if defined(__GNUG__) && !defined (__STRICT_ANSI__)
// G++ implementation internals
extern new_handler __new_handler;
extern "C" void __default_new_handler (void);
#endif

// replaceable signatures
void *operator new (size_t);
void operator delete (void *);
#ifndef _NYI_NEWDEL_ARRAY
void *operator new[] (size_t);
void operator delete[] (void *);
#endif


// default placement versions of operator new
#ifndef _LIBRARY_WORKAROUND
inline void *operator new(size_t, void *place) { return place; }
#endif
#ifndef _NYI_NEWDEL_ARRAY
inline void *operator new[](size_t, void *place) { return place; }
#endif
} // extern "C++"

#endif

/*****************************************************

     ccstddef.h - ANSI-C++ library: standard definitions header
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               
                  Do not modify!
 *****************************************************/

// The -*- C++ -*- standard definitions header.
// This file is part of the GNU ANSI C++ Library.

#ifndef __STDDEF__
#define __STDDEF__

#include "comp.h" /* HIWARE specific DEFINES */
#ifdef _LIBRARY_WORKAROUND

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>



#ifdef __cplusplus
 }
#endif

#endif  /* #if _LIBRARY_WORKAROUND */


#ifdef __GNUG__
#pragma interface "stddef.h"
#endif

#include <Gconfig.h>
#include <cstddef.h>

extern "C++" {

#ifndef _LIBRARY_WORKAROUND  /* dont't DEFINE vars in header files !! */
const size_t NPOS = (size_t)(-1);
#endif

typedef void fvoid_t();

#ifndef _LIBRARY_WORKAROUND
#ifndef _WINT_T
#define _WINT_T
typedef _G_wint_t wint_t;
#endif
#endif

} // extern "C++"

#endif

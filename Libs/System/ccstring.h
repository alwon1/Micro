/*****************************************************

     ccstring.h - ANSI-C++ library: null-terminated string header
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               
                  Do not modify!
 *****************************************************/

// The -*- C++ -*- null-terminated string header.
// This file is part of the GNU ANSI C++ Library.

#ifndef __CCSTRING__
#define __CCSTRING__

#if 0 // Let's not bother with this just yet.
// The ANSI C prototypes for these functions have a const argument type and
// non-const return type, so we can't use them.

#define strchr  __hide_strchr
#define strpbrk __hide_strpbrk
#define strrchr __hide_strrchr
#define strstr  __hide_strstr
#define memchr  __hide_memchr
#endif // 0

#include <cstring.h>

#if 0 // Let's not bother with this just yet.
#undef strchr
#undef strpbrk
#undef strrchr
#undef strstr
#undef memchr

#include <cstddef.h>

#ifdef __GNUG__
#pragma interface "std/cstring.h"
#endif

extern "C++" {
extern "C" const char*_LIBDEF_FAR_CPP_PTR strchr (const char*_LIBDEF_FAR_CPP_PTR , int);
inline char *
strchr (char *s, int c)
{
  return const_cast<char *> (strchr (static_cast<const char*_LIBDEF_FAR_CPP_PTR > (s), c));
}

extern "C" const char*_LIBDEF_FAR_CPP_PTR strpbrk (const char*_LIBDEF_FAR_CPP_PTR , const char*_LIBDEF_FAR_CPP_PTR );
inline char *
strpbrk (char *s1, const char*_LIBDEF_FAR_CPP_PTR s2)
{
  return const_cast<char *> (strpbrk (static_cast<const char*_LIBDEF_FAR_CPP_PTR > (s1), s2));
}

extern "C" const char*_LIBDEF_FAR_CPP_PTR strrchr (const char*_LIBDEF_FAR_CPP_PTR , int);
inline char *
strrchr (char *s, int c)
{
  return const_cast<char *> (strrchr (static_cast<const char*_LIBDEF_FAR_CPP_PTR > (s), c));
}

extern "C" const char*_LIBDEF_FAR_CPP_PTR strstr (const char*_LIBDEF_FAR_CPP_PTR , const char*_LIBDEF_FAR_CPP_PTR );
inline char *
strstr (char *s1, const char*_LIBDEF_FAR_CPP_PTR s2)
{
  return const_cast<char *> (strstr (static_cast<const char*_LIBDEF_FAR_CPP_PTR > (s1), s2));
}

extern "C" const void *memchr (const void *, int, size_t);
inline void *
memchr (void *s, int c, size_t n)
{
  return const_cast<void *> (memchr (static_cast<const void *> (s), c, n));
}
} // extern "C++"

#endif // 0
#endif // !defined (__CCSTRING__)

/*****************************************************
    assert.h - ANSI-C library: primitive debugging
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#ifndef _H_ASSERT_
#define _H_ASSERT_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

#include <libdefs.h>

int _assert (unsigned long line, LIBDEF_ConstStringPtr name);

#ifdef NDEBUG
  #define assert(EX)
#else
  #define assert(EX) ((EX) ? 0 : _assert(__LINE__, __FILE__))
#endif


#ifdef __cplusplus
}
#endif

#endif

/*****************************************************/
/* end assert.h */

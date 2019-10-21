/*****************************************************
 misra.h -  Interface/collection with MISRA related things.
 ----------------------------------------------------
 Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#ifndef _H_MISRA_
#define _H_MISRA_

#ifdef __cplusplus
extern "C" {
#endif

#define __MISRA__

#include <stdtypes.h> /* definition of sByte, etc */

typedef SI_8    sByte;
typedef UI_8    Byte;
typedef SI_16   sWord;
typedef UI_16   Word;
typedef SI_32   sLWord;
typedef UI_32   LWord;
#if defined(__FLOAT_IS_IEEE32__)
  typedef F_32 float;
#elif defined(__DOUBLE_IS_IEEE32__)
  typedef F_32 double;
#endif
#if defined(__DOUBLE_IS_IEEE64__)
  typedef F_64 double;
#elif defined(__FLOAT_IS_IEEE64__)
  typedef F_64 float;
#endif

#ifdef __cplusplus
 }
#endif

#endif
/*****************************************************/
/* end stdtypes.h */

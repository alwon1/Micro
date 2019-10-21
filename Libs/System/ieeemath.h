/*****************************************************
     ieemath.h - ANSI-C library: IEEE handling
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#ifndef _H_IEEEMATH_  
#define _H_IEEEMATH_

#ifdef __cplusplus
extern "C" {
#endif

typedef union {
#if defined(__DOUBLE_IS_IEEE32__)
  unsigned long i;
#else
  unsigned long l[2];
  unsigned short i[4];
#endif  
  double f;
} intdouble;
      
typedef union {
  unsigned long i;
  float f;
} intfloat;
      
extern const intfloat infinityf;
#ifdef __XGATE__
extern const intdouble x_infinity;
#else
extern const intdouble infinity;
#endif

#ifdef __cplusplus
 }
#endif

#endif

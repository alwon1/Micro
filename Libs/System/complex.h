/*****************************************************

     complex.h - ANSI-C++ library: Complex
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               
                  Do not modify!
 *****************************************************/

// Main header for the -*- C++ -*- complex number classes.
// This file is part of the GNU ANSI C++ Library.

#ifndef __COMPLEX__
#define __COMPLEX__

//#include <std/complext.h>
#include <complext.h>

extern "C++" {
#define __STD_COMPLEX

// ANSI complex types
typedef complex<float> float_complex;
typedef complex<double> double_complex;

#ifndef _NYI_LONG_DOUBLE
typedef complex<long double> long_double_complex;
#else
typedef complex<double> long_double_complex;
#endif
}

#endif


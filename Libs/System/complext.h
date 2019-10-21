/*****************************************************

     Complext.h - ANSI-C++ library: Complex
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               
                  Do not modify!
 *****************************************************/
 
// The template and inlines for the -*- C++ -*- complex number classes.
// Copyright (C) 1994 Free Software Foundation

// This file is part of the GNU ANSI C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the terms of
// the GNU General Public License as published by the Free Software
// Foundation; either version 2, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

// As a special exception, if you link this library with files compiled
// with a GNU compiler to produce an executable, this does not cause the
// resulting executable to be covered by the GNU General Public License.
// This exception does not however invalidate any other reasons why the
// executable file might be covered by the GNU General Public License.

// Written by Jason Merrill based upon the specification in the 27 May 1994
// C++ working paper, ANSI document X3J16/94-0098.

#ifndef __COMPLEXT__
#define __COMPLEXT__

#ifdef __GNUG__
#pragma interface
#endif

#include "comp.h"
#include "iostream.h"

//#include <std/cmath.h>
#include <cmath.h>

#if ! defined (__GNUG__) && ! defined (__attribute__)
#ifndef _LIBRARY_WORKAROUND
#define __attribute__ (foo) /* Ignore.  */
#else
#define __attribute__
#endif
#endif

extern "C++" {

template <class FLOAT>
class complex
{
public:
  complex (FLOAT r = 0, FLOAT i = 0): re (r), im (i) { }
  complex& operator += (const complex&);
  complex& operator -= (const complex&);
  complex& operator *= (const complex&);
  complex& operator /= (const complex&);
  FLOAT real () const { return re; }
  FLOAT imag () const { return im; }
private:
  FLOAT re, im;
  // These functions are specified as friends for purposes of name injection;
  // they do not actually reference private members.
#ifndef _LIBRARY_WORKAROUND    
  friend FLOAT real (const complex&) __attribute__ ((const));
  friend FLOAT imag (const complex&) __attribute__ ((const));
  friend complex operator + (const complex&, const complex&) __attribute__ ((const));
  friend complex operator + (const complex&, FLOAT) __attribute__ ((const));
  friend complex operator + (FLOAT, const complex&) __attribute__ ((const));
  friend complex operator - (const complex&, const complex&) __attribute__ ((const));
  friend complex operator - (const complex&, FLOAT) __attribute__ ((const));
  friend complex operator - (FLOAT, const complex&) __attribute__ ((const));
  friend complex operator * (const complex&, const complex&) __attribute__ ((const));
  friend complex operator * (const complex&, FLOAT) __attribute__ ((const));
  friend complex operator * (FLOAT, const complex&) __attribute__ ((const));
  friend complex operator / (const complex&, const complex&) __attribute__ ((const));
  friend complex operator / (const complex&, FLOAT) __attribute__ ((const));
  friend complex operator / (FLOAT, const complex&) __attribute__ ((const));
  friend bool operator == (const complex&, const complex&) __attribute__ ((const));
  friend bool operator == (const complex&, FLOAT) __attribute__ ((const));
  friend bool operator == (FLOAT, const complex&) __attribute__ ((const));
  friend bool operator != (const complex&, const complex&) __attribute__ ((const));
  friend bool operator != (const complex&, FLOAT) __attribute__ ((const));
  friend bool operator != (FLOAT, const complex&) __attribute__ ((const));
  friend complex polar (FLOAT, FLOAT) __attribute__ ((const));
  friend complex pow (const complex&, const complex&) __attribute__ ((const));
  friend complex pow (const complex&, FLOAT) __attribute__ ((const));
  friend complex pow (const complex&, int) __attribute__ ((const));
  friend complex pow (FLOAT, const complex&) __attribute__ ((const));
#else
  friend FLOAT real (const complex&) __attribute__;
  friend FLOAT imag (const complex&) __attribute__;
  friend complex operator + (const complex&, const complex&) __attribute__;
  friend complex operator + (const complex&, FLOAT) __attribute__;
  friend complex operator + (FLOAT, const complex&) __attribute__;
  friend complex operator - (const complex&, const complex&) __attribute__;
  friend complex operator - (const complex&, FLOAT) __attribute__;
  friend complex operator - (FLOAT, const complex&) __attribute__;
  friend complex operator * (const complex&, const complex&) __attribute__;
  friend complex operator * (const complex&, FLOAT) __attribute__;
  friend complex operator * (FLOAT, const complex&) __attribute__;
  friend complex operator / (const complex&, const complex&) __attribute__;
  friend complex operator / (const complex&, FLOAT) __attribute__;
  friend complex operator / (FLOAT, const complex&) __attribute__;
  friend bool operator == (const complex&, const complex&) __attribute__;
  friend bool operator == (const complex&, FLOAT) __attribute__;
  friend bool operator == (FLOAT, const complex&) __attribute__;
  friend bool operator != (const complex&, const complex&) __attribute__;
  friend bool operator != (const complex&, FLOAT) __attribute__;
  friend bool operator != (FLOAT, const complex&) __attribute__;
  friend complex polar (FLOAT, FLOAT) __attribute__;
  friend complex pow (const complex&, const complex&) __attribute__;
  friend complex pow (const complex&, FLOAT) __attribute__;
  friend complex pow (const complex&, int) __attribute__;
  friend complex pow (FLOAT, const complex&) __attribute__;
#endif
  friend istream& operator>> (istream&, complex&);
  friend ostream& operator<< (ostream&, const complex&);
};

// Declare specializations.
class complex<float>;
class complex<double>;
#ifndef _NYI_LONG_DOUBLE
class complex<long double>;
#endif

template <class FLOAT>
inline complex<FLOAT>&
complex<FLOAT>::operator += (const complex<FLOAT>& r)
{
  re += r.re;
  im += r.im;
  return *this;
}

template <class FLOAT>
inline complex<FLOAT>&
complex<FLOAT>::operator -= (const complex<FLOAT>& r)
{
  re -= r.re;
  im -= r.im;
  return *this;
}

template <class FLOAT>
inline complex<FLOAT>&
complex<FLOAT>::operator *= (const complex<FLOAT>& r)
{
  FLOAT f = re * r.re - im * r.im;
  im = re * r.im + im * r.re;
  re = f;
  return *this;
}

template <class FLOAT> inline FLOAT
imag (const complex<FLOAT>& x) __attribute__
{
  return x.imag ();
}

template <class FLOAT> inline FLOAT
real (const complex<FLOAT>& x) __attribute__
{
  return x.real ();
}

template <class FLOAT> inline complex<FLOAT>
operator + (const complex<FLOAT>& x, const complex<FLOAT>& y) __attribute__
{
  return complex<FLOAT> (real (x) + real (y), imag (x) + imag (y));
}

template <class FLOAT> inline complex<FLOAT>
operator + (const complex<FLOAT>& x, FLOAT y) __attribute__
{
  return complex<FLOAT> (real (x) + y, imag (x));
}

template <class FLOAT> inline complex<FLOAT>
operator + (FLOAT x, const complex<FLOAT>& y) __attribute__
{
  return complex<FLOAT> (x + real (y), imag (y));
}

template <class FLOAT> inline complex<FLOAT>
operator - (const complex<FLOAT>& x, const complex<FLOAT>& y) __attribute__
{
  return complex<FLOAT> (real (x) - real (y), imag (x) - imag (y));
}

template <class FLOAT> inline complex<FLOAT>
operator - (const complex<FLOAT>& x, FLOAT y) __attribute__
{
  return complex<FLOAT> (real (x) - y, imag (x));
}

template <class FLOAT> inline complex<FLOAT>
operator - (FLOAT x, const complex<FLOAT>& y) __attribute__
{
  return complex<FLOAT> (x - real (y), - imag (y));
}

template <class FLOAT> inline complex<FLOAT>
operator * (const complex<FLOAT>& x, const complex<FLOAT>& y) __attribute__
{
  return complex<FLOAT> (real (x) * real (y) - imag (x) * imag (y),
         real (x) * imag (y) + imag (x) * real (y));
}

template <class FLOAT> inline complex<FLOAT>
operator * (const complex<FLOAT>& x, FLOAT y) __attribute__
{
  return complex<FLOAT> (real (x) * y, imag (x) * y);
}

template <class FLOAT> inline complex<FLOAT>
operator * (FLOAT x, const complex<FLOAT>& y) __attribute__
{
  return complex<FLOAT> (x * real (y), x * imag (y));
}

template <class FLOAT> complex<FLOAT>
operator / (const complex<FLOAT>& x, FLOAT y) __attribute__
{
  return complex<FLOAT> (real (x) / y, imag (x) / y);
}

template <class FLOAT> inline complex<FLOAT>
operator + (const complex<FLOAT>& x) __attribute__
{
  return x;
}

template <class FLOAT> inline complex<FLOAT>
operator - (const complex<FLOAT>& x) __attribute__
{
  return complex<FLOAT> (-real (x), -imag (x));
}

template <class FLOAT> inline bool
operator == (const complex<FLOAT>& x, const complex<FLOAT>& y) __attribute__
{
  return real (x) == real (y) && imag (x) == imag (y);
}

template <class FLOAT> inline bool
operator == (const complex<FLOAT>& x, FLOAT y) __attribute__
{
  return real (x) == y && imag (x) == 0;
}

template <class FLOAT> inline bool
operator == (FLOAT x, const complex<FLOAT>& y) __attribute__
{
  return x == real (y) && imag (y) == 0;
}

template <class FLOAT> inline bool
operator != (const complex<FLOAT>& x, const complex<FLOAT>& y) __attribute__
{
  return real (x) != real (y) || imag (x) != imag (y);
}

template <class FLOAT> inline bool
operator != (const complex<FLOAT>& x, FLOAT y) __attribute__
{
  return real (x) != y || imag (x) != 0;
}

template <class FLOAT> inline bool
operator != (FLOAT x, const complex<FLOAT>& y) __attribute__
{
  return x != real (y) || imag (y) != 0;
}

// Some targets don't provide a prototype for hypot when -ansi.
extern "C" double hypot (double, double) __attribute__ ;

template <class FLOAT> inline FLOAT
abs (const complex<FLOAT>& x) __attribute__
{
  return hypot (real (x), imag (x));
}

template <class FLOAT> inline FLOAT
arg (const complex<FLOAT>& x) __attribute__
{
  return atan2 (imag (x), real (x));
}

template <class FLOAT> inline complex<FLOAT>
polar (FLOAT r, FLOAT t) __attribute__
{
  return complex<FLOAT> (r * cos (t), r * sin (t));
}

template <class FLOAT> inline complex<FLOAT>
conj (const complex<FLOAT>& x)  __attribute__
{
  return complex<FLOAT> (real (x), -imag (x));
}

template <class FLOAT> inline FLOAT
norm (const complex<FLOAT>& x) __attribute__
{
  return real (x) * real (x) + imag (x) * imag (x);
}

// Declarations of templates in complext.ccI

template <class FLOAT> complex<FLOAT>
  operator / (const complex<FLOAT>&, const complex<FLOAT>&) __attribute__ ;
template <class FLOAT> complex<FLOAT>
  operator / (FLOAT, const complex<FLOAT>&) __attribute__ ;
template <class FLOAT> complex<FLOAT>
  cos (const complex<FLOAT>&) __attribute__ ;
template <class FLOAT> complex<FLOAT>
  cosh (const complex<FLOAT>&) __attribute__ ;
template <class FLOAT> complex<FLOAT>
  exp (const complex<FLOAT>&) __attribute__ ;
template <class FLOAT> complex<FLOAT>
  log (const complex<FLOAT>&) __attribute__ ;
template <class FLOAT> complex<FLOAT>
  pow (const complex<FLOAT>&, const complex<FLOAT>&) __attribute__ ;
template <class FLOAT> complex<FLOAT>
  pow (const complex<FLOAT>&, FLOAT) __attribute__ ;
template <class FLOAT> complex<FLOAT>
  pow (const complex<FLOAT>&, int) __attribute__ ;
template <class FLOAT> complex<FLOAT>
  pow (FLOAT, const complex<FLOAT>&) __attribute__ ;
template <class FLOAT> complex<FLOAT>
  sin (const complex<FLOAT>&) __attribute__ ;
template <class FLOAT> complex<FLOAT>
  sinh (const complex<FLOAT>&) __attribute__ ;
template <class FLOAT> complex<FLOAT>
  sqrt (const complex<FLOAT>&) __attribute__ ;

class istream;
class ostream;
template <class FLOAT> istream& operator >> (istream&, complex<FLOAT>&);
template <class FLOAT> ostream& operator << (ostream&, const complex<FLOAT>&);
} // extern "C++"


#ifdef _LIBRARY_WORKAROUND_TEMPL
extern "C++" {
template <class FLOAT> inline complex<FLOAT>
cos (const complex<FLOAT>& x)
{
  return complex<FLOAT> (cos (real (x)) * cosh (imag (x)),
         - sin (real (x)) * sinh (imag (x)));
}

template <class FLOAT> inline complex<FLOAT>
cosh (const complex<FLOAT>& x)
{
  return complex<FLOAT> (cosh (real (x)) * cos (imag (x)),
         sinh (real (x)) * sin (imag (x)));
}

template <class FLOAT> inline complex<FLOAT>
exp (const complex<FLOAT>& x)
{
  return polar (FLOAT (exp (real (x))), imag (x));
}

template <class FLOAT> inline complex<FLOAT>
log (const complex<FLOAT>& x)
{
  return complex<FLOAT> (log (abs (x)), arg (x));
}

template <class FLOAT> inline complex<FLOAT>
pow (const complex<FLOAT>& x, const complex<FLOAT>& y)
{
  FLOAT logr = log (abs (x));
  FLOAT t = arg (x);

  return polar (FLOAT (exp (logr * real (y) - imag (y) * t)),
    FLOAT (imag (y) * logr + real (y) * t));
}

template <class FLOAT> inline complex<FLOAT>
pow (const complex<FLOAT>& x, FLOAT y)
{
  return exp (FLOAT (y) * log (x));
}

template <class FLOAT> inline complex<FLOAT>
pow (FLOAT x, const complex<FLOAT>& y)
{
  return exp (y * FLOAT (log (x)));
}

template <class FLOAT> inline complex<FLOAT>
sin (const complex<FLOAT>& x)
{
  return complex<FLOAT> (sin (real (x)) * cosh (imag (x)),
         cos (real (x)) * sinh (imag (x)));
}

template <class FLOAT> inline complex<FLOAT>
sinh (const complex<FLOAT>& x)
{
  return complex<FLOAT> (sinh (real (x)) * cos (imag (x)),
         cosh (real (x)) * sin (imag (x)));
}

#include <iostream.h>

template <class FLOAT> inline istream&
operator >> (istream& is, complex<FLOAT>& x)
{
  FLOAT re, im = 0;
  char ch = 0;

  if (is.ipfx0 ())
    {
      if (is.peek () == '(')
  is >> ch;
      is >> re;
      if (ch == '(')
  {
    is >> ch;
    if (ch == ',')
      is >> im >> ch;
  }
    }
  is.isfx ();

  if (ch != 0 && ch != ')')
    is.setstate (ios::failbit);
  else if (is.good ())
    x = complex<FLOAT> (re, im);

  return is;
}

template <class FLOAT> inline ostream&
operator << (ostream& os, const complex<FLOAT>& x)
{
  return os << '(' << real (x) << ',' << imag (x) << ')';
}

// The code below is adapted from f2c's libF77, and is subject to this
// copyright:

/****************************************************************
Copyright 1990, 1991, 1992, 1993 by AT&T Bell Laboratories and Bellcore.

Permission to use, copy, modify, and distribute this software
and its documentation for any purpose and without fee is hereby
granted, provided that the above copyright notice appear in all
copies and that both that the copyright notice and this
permission notice and warranty disclaimer appear in supporting
documentation, and that the names of AT&T Bell Laboratories or
Bellcore or any of their entities not be used in advertising or
publicity pertaining to distribution of the software without
specific, written prior permission.

AT&T and Bellcore disclaim all warranties with regard to this
software, including all implied warranties of merchantability
and fitness.  In no event shall AT&T or Bellcore be liable for
any special, indirect or consequential damages or any damages
whatsoever resulting from loss of use, data or profits, whether
in an action of contract, negligence or other tortious action,
arising out of or in connection with the use or performance of
this software.
****************************************************************/

template <class FLOAT> inline complex<FLOAT>& complex<FLOAT>::
operator /= (const complex& y)
{
  FLOAT ar = abs (y.re);
  FLOAT ai = abs (y.im);
  FLOAT nr, ni;
  FLOAT t, d;
  if (ar <= ai)
    {
      t = y.re / y.im;
      d = y.im * (1 + t*t);
      nr = (re * t + im) / d;
      ni = (im * t - re) / d;
    }
  else
    {
      t = y.im / y.re;
      d = y.re * (1 + t*t);
      nr = (re + im * t) / d;
      ni = (im - re * t) / d;
    }
  re = nr;
  im = ni;
  return *this;
}

template <class FLOAT> inline complex<FLOAT>
operator / (const complex<FLOAT>& x, const complex<FLOAT>& y)
{
  FLOAT ar = abs (real (y));
  FLOAT ai = abs (imag (y));
  FLOAT nr, ni;
  FLOAT t, d;
  if (ar <= ai)
    {
      t = real (y) / imag (y);
      d = imag (y) * (1 + t*t);
      nr = (real (x) * t + imag (x)) / d;
      ni = (imag (x) * t - real (x)) / d;
    }
  else
    {
      t = imag (y) / real (y);
      d = real (y) * (1 + t*t);
      nr = (real (x) + imag (x) * t) / d;
      ni = (imag (x) - real (x) * t) / d;
    }
  return complex<FLOAT> (nr, ni);
}

template <class FLOAT> inline complex<FLOAT>
operator / (FLOAT x, const complex<FLOAT>& y)
{
  FLOAT ar = abs (real (y));
  FLOAT ai = abs (imag (y));
  FLOAT nr, ni;
  FLOAT t, d;
  if (ar <= ai)
    {
      t = real (y) / imag (y);
      d = imag (y) * (1 + t*t);
      nr = x * t / d;
      ni = -x / d;
    }
  else
    {
      t = imag (y) / real (y);
      d = real (y) * (1 + t*t);
      nr = x / d;
      ni = -x * t / d;
    }
  return complex<FLOAT> (nr, ni);
}

template <class FLOAT> inline complex<FLOAT>
pow (const complex<FLOAT>& xin, int y)
{
  if (y == 0)
    return complex<FLOAT> (1.0);
  complex<FLOAT> r (1.0);
  complex<FLOAT> x (xin);
  if (y < 0)
    {
      y = -y;
      x = 1/x;
    }
  for (;;)
    {
      if (y & 1)
  r *= x;
      if (y >>= 1)
  x *= x;
      else
  return r;
    }
}

template <class FLOAT> inline complex<FLOAT>
sqrt (const complex<FLOAT>& x)
{
  FLOAT r = abs (x);
  FLOAT nr, ni;
  if (r == 0.0)
    nr = ni = r;
  else if (real (x) > 0)
    {
      nr = sqrt (0.5 * (r + real (x)));
      ni = imag (x) / nr / 2;
    }
  else
    {
      ni = sqrt (0.5 * (r - real (x)));
      if (imag (x) < 0)
  ni = - ni;
      nr = imag (x) / ni / 2;
    }
  return complex<FLOAT> (nr, ni); 
}
} // extern "C++"

#endif

// Specializations and such

//#include <std/fcomplex.h>
//#include <std/dcomplex.h>
//#include <std/ldcomplex.h>
#include <fcomplex.h>
#include <dcomplex.h>

#ifndef _NYI_OVERLOADING
#include <ldcomplx.h>
#endif

// Declare the instantiations.
#include <cinst.h>

#endif

/******************************************************************************
  FILE        : vregs.h
  PURPOSE     : Run time floating point routines.
                Virtual register definition.
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    24 jun 93   Created.
    09/11/95    renaming M -> _M, L -> _L, K -> _K
 ******************************************************************************/

#ifndef VREGS_H
#define VREGS_H

#ifdef __cplusplus
extern "C" {
#endif


#if 0
******************************************************************************

Internal LONG_32 format
--------------------
LONG_32 = {
  sign:1     == -1 for negative, == 0 for positive.
  exp:16     unused
  mant:32    absolute value of long.
}

******************************************************************************

IEEE32 floating point format
----------------------------

IEEE_32 = {
  sign:1      == 1 for negative, == 0 for positive.
  exp:8
  mant:23
}

val = {
  1.<mant> * 2^(exp-127)   exp != 0, exp != 255
  0.<mant> * 2^(-126)      exp == 0, not-normalized number
  inf                      exp == 255, <mant> == 0
  NaN                      else
}

Internal F32 floating point format
----------------------------------

F_32 = {
  sign:8      == -1 for negative, == 0 for positive
  exp:16
  mant:24
}

value = {
  0.<mant> * 2^(exp-125)
}

********************************************************************

IEEE64 floating point format
----------------------------

IEEE_64 = {
  sign:1      == 1 for negative, == 0 for positive.
  exp:11
  mant:52
}

val = {
  1.<mant> * 2^(exp-1023)   exp != 0, exp != 2047
  0.<mant> * 2^(-1022)      exp == 0, not-normalized number
  inf                       exp == 2047, <mant> == 0
  NaN                       else
}

Internal F64 floating point format
----------------------------------

F_64 = {
  sign:8      == -1 for negative, == 0 for positive
  exp:16
  mant:56
}

value = {
  0.<mant> * 2^(exp-1018)
}
#endif

/*****************************************************************************/

#include "push.sgm"
#include "non_bank.sgm"
#include "runtime.sgm"

extern void UL_PULK (void);

extern void SL_PULK (void);

extern void L_PSHK (void);

extern void L_NEGK (void);

#include "default.sgm"
#include "pop.sgm"

/*****************************************************************************/

#ifdef __cplusplus
 }
#endif

#endif

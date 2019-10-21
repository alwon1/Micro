/******************************************************************************
  FILE        : fregs.h
  PURPOSE     : Run time floating point routines.
                Basic virtual ieee32/f32 register handling.
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    24 jun 93   Created.
 ******************************************************************************/

#ifndef FREGS_H
#define FREGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vregs.h"

/*lint -e451 push.sgm, non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "push.sgm"
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */

/******************************************************************************/

extern void F_PULK (void);

extern void F_PULL (void);

extern void F_PSHK (void);

extern void F_STAL (void);

extern void F_TLK (void);

extern void F_TKL (void);

extern void F_XGKL (void);

extern void F_CLRK (void);

extern void F_CLRL (void);

extern void F_MAXK (void);

extern void F_NORMK (void);

/*****************************************************************************/
/*lint -e451 default.sgm and pop.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "default.sgm"
#include "pop.sgm"
/*lint +e451 */

#ifdef __cplusplus
 }
#endif

#endif

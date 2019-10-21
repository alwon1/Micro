/******************************************************************************
  FILE        : dregs.h
  PURPOSE     : Run time floating point routines.
                Basic virtual ieee64/f64 register handling.
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    24 jun 93   Created.
 ******************************************************************************/

#ifndef DREGS_H
#define DREGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vregs.h"

/******************************************************************************/
/*lint -e451 push.sgm, non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "push.sgm"
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */

extern void D_PULK (void);

extern void D_PULL (void);

extern void D_PSHK (void);

extern void D_STAL (void);

extern void D_TLK (void);

extern void D_TKL (void);

extern void D_XGKL (void);

extern void D_CLRK (void);

extern void D_CLRL (void);

extern void D_MAXK (void);

extern void D_NORMK (void);

/*lint -e451 default.sgm and pop.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "default.sgm"
#include "pop.sgm"
/*lint +e451 */
/*****************************************************************************/

#ifdef __cplusplus
 }
#endif

#endif

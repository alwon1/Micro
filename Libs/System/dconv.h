/******************************************************************************
  FILE        : dregs.h
  PURPOSE     : Run time floating point routines.
                Basic virtual ieee64/f64 register handling.
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    24 jun 93   Created.
 ******************************************************************************/

#ifndef DCONV_H
#define DCONV_H

#ifdef __cplusplus
extern "C" {
#endif

/*lint -e451 push.sgm, non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "push.sgm"
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */
/******************************************************************************/

extern void D_PSHK_UNARY (void);

extern void D_CLRK_UNARY (void);

extern void D_MAXK_UNARY (void);

extern void D_NORMK_UNARY (void);

/*****************************************************************************/

/*lint -e451 default.sgm and pop.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "default.sgm"
#include "pop.sgm"
/*lint +e451 */

#ifdef __cplusplus
 }
#endif

#endif

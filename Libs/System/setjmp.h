/*****************************************************
      setjmp.h - ANSI-C library: non-local jumps
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#ifndef _H_SETJMP_
#define _H_SETJMP_

#ifdef __cplusplus
extern "C" {
#endif

/**** Implementation for Freescale 68HC12  */

typedef struct JMPB {
  unsigned int  sp;
  void (*pc) (void);
} jmp_buf[1];

/*lint -esym(828,setjmp) , according to ANSI-C, setjmp must be a macro */
#define setjmp(buf) _setjmp(buf)
/*lint +esym(828,setjmp) */

#ifdef __LARGE__
#include "push.sgm"
#include "non_bank.sgm"
#endif

#if defined(__LARGE__) || defined(__BANKED__)
#define __LONGJMP_FAR far
#else
#define __LONGJMP_FAR
#endif


extern int __LONGJMP_FAR _setjmp (jmp_buf env);

extern void __LONGJMP_FAR longjmp (jmp_buf env, int res);

#ifdef __LARGE__
#include "default.sgm"
#include "pop.sgm"
#endif

#ifdef __cplusplus
 }
#endif

#endif

/*****************************************************/
/* end setjmp.h */

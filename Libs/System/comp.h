/*****************************************************

     comp.h - ANSI-C++ library: defines of compiler dependent stuff about making the C++ library.
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               
                  Do not modify!
 *****************************************************/

#ifndef _COMP_H
#define _COMP_H

#ifdef __cplusplus
extern "C" {
#endif
  void exit(int);
#ifdef __cplusplus  
}
#endif

#include "hidef.h"
#if 0  /* use configurable define _LIBDEF_FAR_CPP_PTR instead of _FAR */
#ifdef __HC12__   /* HC12 does not support far strings yet */
#undef  FAR
#undef  NEAR
#undef _FAR
#undef _NEAR

#define  FAR
#define  NEAR
#define _FAR
#define _NEAR
#endif
#else
#include "libdefs.h"
#endif

/* NYI stuff of HIWARE compiler */
#define _NYI_PLAIN_CHAR
#define _NYI_LONG_DOUBLE
#define _NYI_EXPL_OP_CALL         /* explicit operator call */
#define _NYI_OVERLOADING          /* overloading is not fully supported yet */
#define _NYI_ALTERNATIVE_CASTING
#define _NYI_NEWDEL_ARRAY         /* operator new[] ();  operator delete[] (); */

#define bool int                  /* C++ keyword */
#define explicit                  /* C++ keyword */

/* NYI stuff of C++ library */
#define _NYI_LIB

/* HIWARE compiler dependend stuff */
#define _VIRTUAL_IMPLEMENTATION   /* layout of virtual tables, vtptr and vbtptr */
#define _HICROSS_8                /* preprocessor problem */
#define _LIMITATION_XA            /* compiler memory management problem in XA (too many declarations?) */

#ifdef __HC05__
  #define _LIMITATION_HC05        /* Error C17300 Arguments too complex for function pointer call */
#endif

/* limitations in HIWARE ANSI C lib */
#define _C_LIB_LIMIT_PUTC           /* stdio.h has non-standard putc() */
#define _C_LIB_LIMIT_IMPL           /* implementations of fflush, fprintf, fputs, ... missing */

/* workarounds for non-standard GNU C++ lib parts */
#define _LIBRARY_WORKAROUND_PLAC  /* placement versions only allowed in new operator inside classes! */
#define _LIBRARY_WORKAROUND       /* general standard problem */
#define _LIBRARY_WORKAROUND_TEMPL /* templates standard problem */

/* the following part disables messages which are not showing any problems for the library */
#pragma MESSAGE DISABLE C1048 /* INFORMATION C1048: Generate compiler defined Default Copy Ctor */
#pragma MESSAGE DISABLE C1109 /* INFORMATION C1109: Generate call to Copy Constructor */
#pragma MESSAGE DISABLE C1390 /* INFORMATION C1390: Implicit virtual function */
#pragma MESSAGE DISABLE C1391 /* INFORMATION C1391: Pseudo Base Class is added to this class */
#pragma MESSAGE DISABLE C1420 /* WARNING     C1420: Result of function-call is ignored */
#pragma MESSAGE DISABLE C2021 /* INFORMATION C2021: Generate NULL-check for _strbuf class pointer */
#pragma MESSAGE DISABLE C4002 /* WARNING     C4002: Result not used */
#pragma MESSAGE DISABLE C4003 /* INFORMATION C4003: Shift count converted to unsigned char */
#pragma MESSAGE DISABLE C5703 /* INFORMATION C5703: format: parameter declared in function scan but not referenced */
#pragma MESSAGE DISABLE C1045 /* WARNING     C1045: Default Copy Ctor not generated */
#pragma MESSAGE DISABLE C4443 /* WARNING     C4443: Undefined Macro '_G_HAVE_BOOL' is taken as 0 */
#ifdef __HC12__
#pragma MESSAGE DISABLE C12056 /*WARNING C12056: SP debug info incorrect because of optimization or inline assembler */
#endif
#endif


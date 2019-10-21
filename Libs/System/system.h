/*****************************************************
      system.h - interface to runtime routines
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#ifndef system_h
#define system_h

#ifdef __cplusplus
extern "C" {
#endif

void _FMUL (void);

void _FDIV (void);

void _FADD (void);

void _FCMP (void);

void _FSFLOAT (void);

void _FUFLOAT (void);

void _FSTRUNC (void);

void _FUTRUNC (void);

void _DMUL (void);

void _DDIV (void);

void _DADD (void);

void _DCMP (void);

void _DSFLOAT (void);

void _DUFLOAT (void);

void _DSTRUNC (void);

void _DUTRUNC (void);

void _DLONG (void);

void _DSHORT (void);

void _LDIV(void);

void _MOD(void);

void _DIV(void);

void _LMUL(void);

void _MULU32(void);

void _DIVU32(void);

void _MULS32(void);

void _DIVS32(void);

#ifdef __cplusplus
 }
#endif

#endif




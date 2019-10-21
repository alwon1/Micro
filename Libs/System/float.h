/*****************************************************
    float.h - ANSI-C library: floating point format
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#ifndef _H_FLOAT_
#define _H_FLOAT_

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__HIWARE__) && defined(__MWERKS__) && defined(__PPC__)
  /* Metrowerks PowerPC compiler does not define the stuff below */
  #define __FLOAT_IS_IEEE32__
  #define __DOUBLE_IS_IEEE64__
#endif

/**** Rounding Mode */

#define FLT_ROUNDS         -1
#define FLT_RADIX           2

/**** float */

#ifdef __FLOAT_IS_IEEE32__

#define FLT_MANT_DIG       24
#define FLT_DIG             6
#define FLT_MIN_EXP      -126
#define FLT_MIN_10_EXP    -37
#define FLT_MAX_EXP       127
#define FLT_MAX_10_EXP     38
#define FLT_MAX             3.402823466E+38F    
#define FLT_EPSILON         1.19209290E-07F
#define FLT_MIN             1.17549435E-38F

#endif

#ifdef __DOUBLE_IS_IEEE32__
/**** double */

#define DBL_MANT_DIG       FLT_MANT_DIG
#define DBL_DIG            FLT_DIG
#define DBL_MIN_EXP        FLT_MIN_EXP
#define DBL_MIN_10_EXP     FLT_MIN_10_EXP
#define DBL_MAX_EXP        FLT_MAX_EXP
#define DBL_MAX_10_EXP     FLT_MAX_10_EXP
#define DBL_MAX            FLT_MAX
#define DBL_EPSILON        FLT_EPSILON
#define DBL_MIN            FLT_MIN

#endif

#ifdef __DOUBLE_IS_IEEE64__
/**** double */

#define DBL_MANT_DIG       53
#define DBL_DIG            15
#define DBL_MIN_EXP     -1022
#define DBL_MIN_10_EXP   -307
#define DBL_MAX_EXP      1023
#define DBL_MAX_10_EXP    308
#define DBL_MAX             1.7976931348623157E+308
#define DBL_EPSILON         2.2204460492503131E-16
#define DBL_MIN             2.2259738585972014E-308

#endif



#ifdef __FLOAT_IS_DSP__
/* DSP float */

#define FLT_MANT_DIG       16
#define FLT_DIG             4
#define FLT_MIN_EXP      -32768
#define FLT_MIN_10_EXP    -9863
#define FLT_MAX_EXP       32767
#define FLT_MAX_10_EXP     9863
#define FLT_MAX             0.9999695E+9863F    
#define FLT_EPSILON         3.051757E-05F
#define FLT_MIN             0.9999695E+9863F

#endif

#ifdef __DOUBLE_IS_DSP__
/**** double */

#define DBL_MANT_DIG         16                
#define DBL_DIG               4                
#define DBL_MIN_EXP        -32768              
#define DBL_MIN_10_EXP      -9863              
#define DBL_MAX_EXP         32767              
#define DBL_MAX_10_EXP       9863              
#define DBL_MAX               0.9999695E+9863F 
#define DBL_EPSILON           3.051757E-05F    
#define DBL_MIN               0.9999695E+9863F 

#endif

/**** long double */

#define LDBL_MANT_DIG    DBL_MANT_DIG
#define LDBL_DIG         DBL_DIG
#define LDBL_MIN_EXP     DBL_MIN_EXP
#define LDBL_MIN_10_EXP  DBL_MIN_10_EXP
#define LDBL_MAX_EXP     DBL_MAX_EXP
#define LDBL_MAX_10_EXP  DBL_MAX_10_EXP
#define LDBL_MAX         DBL_MAX
#define LDBL_EPSILON     DBL_EPSILON
#define LDBL_MIN         DBL_MIN


#ifdef __cplusplus
 }
#endif

#endif

/*****************************************************/
/* end float.h */

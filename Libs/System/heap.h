/*****************************************************
      heap.h - ANSI-C library: heap definition
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#ifndef _H_HEAP_
#define _H_HEAP_

#ifdef __cplusplus
extern "C" {
#endif

#include <libdefs.h>

#ifdef __XGATE__
#define _heap_    _X__heap_
  /*!< XGATE heap */
#endif /* __XGATE__ */


#define  ERR_HEAP_ALLOC  1
  /*!< free-list distroyed; found while allocating */
#define  ERR_HEAP_FREE   2
  /*!< freeing already freed or distroyed block   */
#define  ERR_HEAP_RANGE  3
  /*!< freeing block outside of pool               */
#define  ERR_HEAP_REALL  4
  /*!< free list crashed; found while reallocating */

#if LIBDEF_FAR_HEAP_DATA
  #pragma DATA_SEG __FAR_SEG HEAP_SEGMENT
#else
  #pragma DATA_SEG     HEAP_SEGMENT
#endif
extern unsigned long _heap_[];
  /*!< heap we are using for malloc() and free() */
#pragma DATA_SEG DEFAULT
  
extern void _heapcrash_(void *LIBDEF_HEAP_DPTRQ where, int cause);
  /*!< hook routine called on heap corruption */

#ifdef __cplusplus
 }
#endif

#endif

/*****************************************************/
/* end heap.h */

/******************************************************************************
  FILE    : startup.h
  PURPOSE : data structures for startup
  LANGUAGE: ANSI-C
********************************************************************************/
#ifndef STARTUP_H
#define STARTUP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdtypes.h>
#include <hidef.h>

#ifdef __HC16__
  #define PTR_QUAL  far  /* all data pointers are here far for the HC16 */
#else
  #define PTR_QUAL  /* none */
#endif

#ifndef __HIWARE__
  #define __OPTION_ACTIVE__(x) 0 /* not supported */
#endif

#if defined(__HC12__) || defined(__XGATE__)
  #define LARGE_SIZE 0
#elif defined(__M68K__) && __OPTION_ACTIVE__("-Cl") && defined(__ELF_OBJECT_FILE_FORMAT__) && !defined(__SMALL_SHORT__) && !defined(__MEDIUM_SHORT__)
  #define LARGE_SIZE 1
#else
  #define LARGE_SIZE 0
#endif

/* the following datastructures contain the data needed to
   initialize the processor and memory */
typedef struct _Range{
  unsigned char  *PTR_QUAL beg;     
#if LARGE_SIZE
  long           size;      /* [beg..beg+size] */
#else
  int            size;      /* [beg..beg+size] */
#endif
}_Range, *PTR_QUAL _RangePtr;

typedef struct _tagStartup *PTR_QUAL _StartupPtr;
typedef const struct _tagStartup *PTR_QUAL _ConstStartupPtr;

#if defined(__ELF_OBJECT_FILE_FORMAT__)
  typedef struct _tagStartup *_LibInitStartupPtr;
#else
  typedef void(*_LibInitStartupPtr)(void);
  #define _LIBINIT_STARTUP_SENTINEL 0xFFFF
#endif

typedef struct _LibInit{
  _LibInitStartupPtr startup;  /* address of startup desc */
}_LibInit, *PTR_QUAL _LibInitPtr;

typedef struct _Copy{
#if LARGE_SIZE
  long          size;
#else
  int           size;      /* [beg..beg+size] */
#endif
#if defined(__HC16__) && !defined(__ELF_OBJECT_FILE_FORMAT__)
  Byte filler;
#endif
  unsigned char *PTR_QUAL dest;
}_Copy, *PTR_QUAL _CopyPtr;

typedef void (*_PFunc)(void);
typedef _PFunc*PTR_QUAL _mInitPtr; 

#define STARTUP_FLAGS_NONE          0
#define STARTUP_FLAGS_ROM_LIB       (1U<<0)  /* if module is a ROM library */
#define STARTUP_FLAGS_NOT_INIT_SP   (1U<<1)  /* if stack pointer has NOT
                                               to be initialized */
#ifdef __ELF_OBJECT_FILE_FORMAT__
/* attention: the linker scans the debug information for these structures */
/* to obtain the available fields and their sizes. */
/* So do not change the names in this file. */

typedef struct _Cpp{
  _PFunc  initFunc;      /* address of init function */
}_Cpp;

extern struct _tagStartup {
#if defined(__MCORE__)
  unsigned int   flags;         /* STARTUP_FLAGS_xxx */
  unsigned int   nofZeroOuts;   /* number of zero out ranges */
  unsigned int   nofLibInits;   /* number of library startup descriptors */
  unsigned int   nofInitBodies; /* number of C++ constructors */
  unsigned int   nofFiniBodies; /* number of C++ destructors */
  unsigned long  stackOffset;   /* initial value of the stack pointer */
#else
  unsigned char  flags;         /* STARTUP_FLAGS_xxx */
  unsigned short nofZeroOuts;   /* number of zero out ranges */
  unsigned short nofLibInits;   /* number of library startup descriptors */
  unsigned short nofInitBodies; /* number of C++ constructors */
  unsigned short nofFiniBodies; /* number of C++ destructors */
#if defined(__M68K__) || defined(__PPC__)
  unsigned long  stackOffset;   /* initial value of the stack pointer */
#else
  unsigned short stackOffset;   /* initial value of the stack pointer */
#endif
#endif
  _PFunc         main;          /* top level procedure of user program */
  _Range         *pZeroOut;     /* vector of ranges with nofZeroOuts elements */ 
  _Copy          *toCopyDownBeg;/* rom-address where copydown-data begins */
  _LibInit       *libInits;     /* vector of pointers to library startup descriptors */
  _Cpp           *initBodies;   /* vector of function pointers to C++ constructors */
  _Cpp           *finiBodies;   /* vector of function pointers to C++ destructors */
} _startupData;    

#else /* HIWARE object file format */

extern struct _tagStartup {
  Word           flags;        /* STARTUP_FLAGS_xxx */  
  _PFunc         main;         /* top procedure of user program */
  Word           dataPage;     /* page where data allocation begins */
  LWord          stackOffset;  /* initial value of the stack pointer */
  Word           nofZeroOuts;  /* number of zero out ranges */
  _RangePtr      pZeroOut;    /* pZeroOut is a vector of ranges with
                                  nofZeroOuts elements */
#ifdef __HC16__
  Byte             filler;      /* dummy value */
  _CopyPtr       toCopyDownBeg; /* rom-address where copydown-data begins */
#else
  LWord          toCopyDownBeg; /* rom-address where copydown-data begins */
#endif
  _mInitPtr      mInits;       /* mInits is a pointer to an array of function
                                  pointers containing the addresses of the global
                                  C++ constructors in the application, sorted in
                                  the order they have to be called. The array is
                                  terminated by a single zero entry. */
  _LibInitPtr    libInits;     /* libInits is a pointer to an array of pointers
                                  to the _startupData records of all ROM
                                  libraries in the application. These addresses
                                  are needed to initialize the ROM libraries.
                                  To specify the end of the array, the last array
                                  element contains the value 0x0000ffff. */
} _startupData;  
#endif  

#ifdef __HC11__
  extern void NEAR _Startup(void);
#else
  extern void _Startup(void);    /* execution begins in this procedure */
#endif
/*--------------------------------------------------------------------*/

#ifdef __cplusplus
 }
#endif

#endif



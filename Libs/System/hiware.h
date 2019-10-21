#ifndef __HIWARE_H__
#define __HIWARE_H__

#include <stdtypes.h>

#define BIGENDIAN
/*!< One of the macros `BIGENDIAN' or `LITTLEENDIAN' must be defined. */

/*
-------------------------------------------------------------------------------
The macro `BITS64' can be defined to indicate that 64-bit integer types are
supported by the compiler.
-------------------------------------------------------------------------------
*/
#if defined(__LONG_LONG_IS_64BIT__) || defined(__LONG_IS_64BIT__)
 #define BITS64
#endif

/*
-------------------------------------------------------------------------------
Each of the following `typedef's defines the most convenient type that holds
integers of at least as many bits as specified.  For example, `uint8' should
be the most convenient type that can hold unsigned integers of as many as
8 bits.  The `flag' type must be able to hold either a 0 or 1.  For most
implementations of C, `flag', `uint8', and `int8' should all be `typedef'ed
to the same as `int'.
-------------------------------------------------------------------------------
*/
typedef Byte flag;
typedef Byte uint8;
typedef sByte int8;
typedef Word uint16;
typedef sWord int16;
typedef LWord uint32;
typedef sLWord int32;
#ifdef BITS64
typedef LLWord bits64;
typedef sLLWord sbits64;
#endif

/*
-------------------------------------------------------------------------------
Each of the following `typedef's defines a type that holds integers
of _exactly_ the number of bits specified.  For instance, for most
implementation of C, `bits16' and `sbits16' should be `typedef'ed to
`unsigned short int' and `signed short int' (or `short int'), respectively.
-------------------------------------------------------------------------------
*/
typedef Byte bits8;
typedef sByte sbits8;
typedef Word bits16;
typedef sWord sbits16;
typedef LWord bits32;
typedef sLWord sbits32;
#ifdef BITS64
typedef LLWord uint64;
typedef sLLWord int64;
#endif

#ifdef BITS64
/*
-------------------------------------------------------------------------------
The `LIT64' macro takes as its argument a textual integer literal and if
necessary ``marks'' the literal as having a 64-bit integer type.  For
example, the Gnu C Compiler (`gcc') requires that 64-bit literals be
appended with the letters `LL' standing for `long long', which is `gcc's
name for the 64-bit integer type.  Some compilers may allow `LIT64' to be
defined as the identity macro:  `#define LIT64( a ) a'.
-------------------------------------------------------------------------------
*/
#define LIT64( a ) a##LL
#endif


#endif

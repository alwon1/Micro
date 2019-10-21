/******************************************************************************
  FILE        : checksum.h 
  PURPOSE     : checksum calculation interface
  LANGUAGE    : ANSI-C
  -----------------------------------------------------------------------------
  HISTORY 
    19 sep 2002       Created.
 ******************************************************************************/

#ifndef _CHECKSUM_H_
#define _CHECKSUM_H_

#ifdef __HIWARE__
/* HIWARE target compiler */
#include <hidef.h>  /* for FALSE/TRUE */
#include <libdefs.h>

#if defined(_CHECKSUM_USE_FAR_PTR) && !defined(_CHECKSUM_QUALI)
#define _CHECKSUM_QUALI __far
#elif !defined(_CHECKSUM_QUALI)
#define _CHECKSUM_QUALI LIBDEF_VOID_DPTRQ
#endif

#else /* __HIWARE__ */

/* any host compiler (only used to generate the tables in checksum.c) */
#define LIBDEF_VOID_DPTRQ /* nothing */
typedef int Bool;
#define TRUE 1
#define FALSE 0
#endif /* __HIWARE__ */

typedef const LIBDEF_MemByte *_CHECKSUM_QUALI     _CHECKSUM_ConstMemBytePtr; /* pointer to a constant byte in memory */


#if 0 /* check them all? */
#define _CHECKSUM_CHECKSUMS_
#endif


/* notes: the 2 or 4 byte xor or add checksums do have problems with not actually allocated memory at the area boundaries */
/* for example, for "const char something@0x7777=0x12;" these algorithms are using a undefined byte at 0x7776. */
/* therefore it is not recommended to use them unless you do always allocate things in a multiple of this size */

#ifdef _CHECKSUM_CHECKSUMS_  /* internal test switch only. Generates redundant checks. */
#define _CHECKSUM_CRC_CCITT 1
#define _CHECKSUM_CRC_8     1
#define _CHECKSUM_CRC_16    1
#define _CHECKSUM_CRC_32    1
#define _CHECKSUM_ADD_BYTE  1
#define _CHECKSUM_ADD_WORD  0 /* careful: this one only works when all the addresses/sizes are a multiple of 2 */
#define _CHECKSUM_ADD_LONG  0 /* careful: this one only works when all the addresses/sizes are a multiple of 4 */
#define _CHECKSUM_XOR_BYTE  1
#define _CHECKSUM_XOR_WORD  0 /* careful: this one only works when all the addresses/sizes are a multiple of 2 */
#define _CHECKSUM_XOR_LONG  0 /* careful: this one only works when all the addresses/sizes are a multiple of 4 */
#else

#ifndef _CHECKSUM_CRC_CCITT  
#define _CHECKSUM_CRC_CCITT  0
#endif

#ifndef _CHECKSUM_CRC_8
#define _CHECKSUM_CRC_8   1	 /* used by default*/
#endif

#ifndef _CHECKSUM_CRC_16
#define _CHECKSUM_CRC_16  0
#endif

#ifndef _CHECKSUM_CRC_32
#define _CHECKSUM_CRC_32  0
#endif

#ifndef _CHECKSUM_ADD_BYTE
#define _CHECKSUM_ADD_BYTE 0
#endif

#ifndef _CHECKSUM_ADD_WORD  /* careful: this one only works when all the addresses/sizes are  a multiple of 2 */
#define _CHECKSUM_ADD_WORD 0
#endif

#ifndef _CHECKSUM_ADD_LONG  /* careful: this one only works when all the addresses/sizes are  a multiple of 4 */
#define _CHECKSUM_ADD_LONG 0
#endif

#ifndef _CHECKSUM_XOR_BYTE
#define _CHECKSUM_XOR_BYTE 0
#endif

#ifndef _CHECKSUM_XOR_WORD   /* careful: this one only works when all the addresses/sizes are  a multiple of 2 */
#define _CHECKSUM_XOR_WORD 0
#endif

#ifndef _CHECKSUM_XOR_LONG    /* careful: this one only works when all the addresses/sizes are  a multiple of 4 */
#define _CHECKSUM_XOR_LONG 0
#endif

#endif

#ifndef __FEED_COP /* define this macro accordingly, if you are using a COP (computer operates properly) and the checksum computation takes too long. */
#define __FEED_COP _FEED_COP();
#endif 

/* special types for checksum calculation with known sizes */
typedef unsigned char  _CheckSum1ByteType;
typedef unsigned short _CheckSum2ByteType;
typedef unsigned long  _CheckSum4ByteType;

#define DEFAULT_CRC8_CHECKSUM  ((_CheckSum1ByteType)(/*(1 << 8) +*/ (1 << 7) + (1 << 4) + (1 << 3) + (1 << 1) + (1 << 0)))
#define DEFAULT_CRC16_CHECKSUM ((_CheckSum2ByteType)(/*(1 << 16) +*/ (1 << 15) + (1 << 2) + (1 << 0)))  /* G(x)=X**16+X**15+X**2+1 */
#define DEFAULT_CRC32_CHECKSUM ((_CheckSum4ByteType)0x04C11DB7)  /* G(x)=x**26+x**23+x**22+x**16+x**12+x**11+x**10+x**8+x**7+x**5+x**4+x**2+x**1+1=0 */

/* calculates one byte step of the CRC CCITT computation */
_CheckSum2ByteType CheckSumByteCRC_CCITT(_CheckSum2ByteType crc, _CheckSum1ByteType val);

/* calculates one byte step of the CRC8 computation */
_CheckSum1ByteType CheckSumByteCRC8(_CheckSum1ByteType crc, _CheckSum1ByteType val, _CheckSum1ByteType poly);

/* calculates one byte step of the CRC16 computation */
_CheckSum2ByteType CheckSumByteCRC16(_CheckSum2ByteType crc, _CheckSum1ByteType val, _CheckSum2ByteType poly);

/* calculates one byte step of the CRC32 computation */
_CheckSum4ByteType CheckSumByteCRC32(_CheckSum4ByteType crc, _CheckSum1ByteType val, _CheckSum4ByteType poly);

/* calculates one byte step of the CRC CCITT computation with a precalculated table */
_CheckSum2ByteType CheckSumByteCRC_CCITT_PreCalc(_CheckSum2ByteType crc, _CheckSum1ByteType val);

/* calculates one byte step of the CRC8 computation with the default polynom with a precalculated table */
_CheckSum1ByteType CheckSumByteCRC8_PreCalc(_CheckSum1ByteType crc, _CheckSum1ByteType val);

/* calculates one byte step of the CRC16 computation with the default polynom with a precalculated table */
_CheckSum2ByteType CheckSumByteCRC16_PreCalc(_CheckSum2ByteType crc, _CheckSum1ByteType val);

/* calculates one byte step of the CRC32 computation with the default polynom with a precalculated table */
_CheckSum4ByteType CheckSumByteCRC32_PreCalc(_CheckSum4ByteType crc, _CheckSum1ByteType val);

/* _Checksum_CheckAreaCRC_CCITT: CRC CCITT checksum of an aera */
_CheckSum2ByteType _Checksum_CheckAreaCRC_CCITT(_CHECKSUM_ConstMemBytePtr start, unsigned int len);

/* _Checksum_CheckAreaCRC8: CRC8 checksum of an aera */
_CheckSum1ByteType _Checksum_CheckAreaCRC8(_CHECKSUM_ConstMemBytePtr start, unsigned int len, _CheckSum1ByteType poly, _CheckSum1ByteType init);

/* _Checksum_CheckAreaCRC16: CRC16 checksum of an aera */
_CheckSum2ByteType _Checksum_CheckAreaCRC16(_CHECKSUM_ConstMemBytePtr start, unsigned int len, _CheckSum2ByteType poly, _CheckSum2ByteType init);

/* _Checksum_CheckAreaCRC32: CRC32 checksum of an aera */
_CheckSum4ByteType _Checksum_CheckAreaCRC32(_CHECKSUM_ConstMemBytePtr start, unsigned int len, _CheckSum4ByteType poly, _CheckSum4ByteType init);

/* _Checksum_CheckAreaCRC_CCITT_PreCalc: CCITT checksum of an aera */
_CheckSum2ByteType _Checksum_CheckAreaCRC_CCITT_PreCalc(_CHECKSUM_ConstMemBytePtr start, unsigned int len);

/* _Checksum_CheckAreaCRC8: CRC8 checksum of an aera with the default polynom */
_CheckSum1ByteType _Checksum_CheckAreaCRC8_PreCalc(_CHECKSUM_ConstMemBytePtr start, unsigned int len);

/* _Checksum_CheckAreaCRC16: CRC16 checksum of an aera with the default polynom */
_CheckSum2ByteType _Checksum_CheckAreaCRC16_PreCalc(_CHECKSUM_ConstMemBytePtr start, unsigned int len);

/* _Checksum_CheckAreaCRC32: CRC32 checksum of an aera with the default polynom */
_CheckSum4ByteType _Checksum_CheckAreaCRC32_PreCalc(_CHECKSUM_ConstMemBytePtr start, unsigned int len);

/* _Checksum_CheckAreaByteAdd: byte summation checksum of an aera */
_CheckSum1ByteType _Checksum_CheckAreaByteAdd(_CHECKSUM_ConstMemBytePtr start, unsigned int len);

/* _Checksum_CheckAreaWordAdd: word summation checksum of an aera */
_CheckSum2ByteType _Checksum_CheckAreaWordAdd(_CHECKSUM_ConstMemBytePtr start, unsigned int len);

/* _Checksum_CheckAreaLongAdd: long summation checksum of an aera */
_CheckSum4ByteType _Checksum_CheckAreaLongAdd(_CHECKSUM_ConstMemBytePtr start, unsigned int len);

/* _Checksum_CheckAreaByteXor: byte xor checksum of an aera */
_CheckSum1ByteType _Checksum_CheckAreaByteXor(_CHECKSUM_ConstMemBytePtr start, unsigned int len);

/* _Checksum_CheckAreaWordXor: word xor checksum of an aera */
_CheckSum2ByteType _Checksum_CheckAreaWordXor(_CHECKSUM_ConstMemBytePtr start, unsigned int len);

/* _Checksum_CheckAreaLongXor: long xor checksum of an aera */
_CheckSum4ByteType _Checksum_CheckAreaLongXor(_CHECKSUM_ConstMemBytePtr start, unsigned int len);




/* Note: if this structure is referenced from the _startupData element in ELF, then the linker */
/* reads the debug info of the compiler and generates its content as it is defined here */
/* so setting an additional define and rebuilding the startup code will cause the linker to generate this */
/* additional field automatically. */
/* Note: This only works in ELF. You can change the field types, but do not change the field names or the name of the structure. */
struct __Checksum {
    void*_CHECKSUM_QUALI start;
    unsigned int len;
#if _CHECKSUM_CRC_CCITT
    _CheckSum2ByteType checkSumCRC_CCITT;
#endif
#if _CHECKSUM_CRC_8
    _CheckSum1ByteType checkSumCRC8;
#endif
#if _CHECKSUM_CRC_16
    _CheckSum2ByteType checkSumCRC16;
#endif
#if _CHECKSUM_CRC_32
    _CheckSum4ByteType checkSumCRC32;
#endif
#if _CHECKSUM_ADD_BYTE
    _CheckSum1ByteType checkSumByteAdd; /* note: you can use also _CheckSum4ByteType or _CheckSum2ByteType here. Using a larger type just keeps the overflow. */
#endif
#if _CHECKSUM_ADD_WORD
    _CheckSum2ByteType checkSumWordAdd; /* note: you can use also _CheckSum4ByteType here. Using a larger type just keeps the overflow. */
#endif
#if _CHECKSUM_ADD_LONG
    _CheckSum4ByteType checkSumLongAdd;
#endif
#if _CHECKSUM_XOR_BYTE
    _CheckSum1ByteType checkSumByteXor;
#endif
#if _CHECKSUM_XOR_WORD
    _CheckSum2ByteType checkSumWordXor;
#endif
#if _CHECKSUM_XOR_LONG
    _CheckSum4ByteType checkSumLongXor;
#endif
};

// Add this macro to the startup data structure to enable automatic checksums
#define _CHECKSUM_STARTUP_ENTRY     \
        struct __Checksum* _CHECKSUM_QUALI checkSum; \
        int nofCheckSums;            \

// call the checksum function like this (or just use the macro):
#define __CHECKSUM_IS_OK  (_Checksum_Check(_startupData.checkSum, _startupData.nofCheckSums))

/* check all the checksums */
/* returns TRUE (1) when the checksums are OK, FALSE otherwise */
int _Checksum_Check(const struct __Checksum* _CHECKSUM_QUALI check, int num);

//To calculate single checksum for multiple memory areas

struct __ChecksumArea {
  _CHECKSUM_ConstMemBytePtr start;
  unsigned int len;
};

/* _Checksum_CheckAreaCRC_CCITT: CRC CCITT checksum of multiple mem areas */
_CheckSum2ByteType _Checksum_CheckAreasCRC_CCITT(const struct __ChecksumArea * areas,int num,_CheckSum2ByteType init);

/* _Checksum_CheckAreaCRC8: CRC8 checksum of multiple mem areas */
_CheckSum1ByteType _Checksum_CheckAreasCRC8(const struct __ChecksumArea * areas,int num, _CheckSum1ByteType poly, _CheckSum1ByteType init);

/* _Checksum_CheckAreaCRC16: CRC16 checksum of multiple mem areas */
_CheckSum2ByteType _Checksum_CheckAreasCRC16(const struct __ChecksumArea * areas,int num, _CheckSum2ByteType poly, _CheckSum2ByteType init);

/* _Checksum_CheckAreaCRC32: CRC32 checksum of multiple mem areas*/
_CheckSum4ByteType _Checksum_CheckAreasCRC32(const struct __ChecksumArea * areas,int num, _CheckSum4ByteType poly, _CheckSum4ByteType init);

/* _Checksum_CheckAreaByteAdd: byte summation checksum of multiple mem areas */
_CheckSum1ByteType _Checksum_CheckAreasByteAdd(const struct __ChecksumArea * areas,int num);

/* _Checksum_CheckAreaWordAdd: word summation checksum of multiple mem areas */
_CheckSum2ByteType _Checksum_CheckAreasWordAdd(const struct __ChecksumArea * areas,int num);

/* _Checksum_CheckAreaLongAdd: long summation checksum of multiple mem areas */
_CheckSum4ByteType _Checksum_CheckAreasLongAdd(const struct __ChecksumArea * areas,int num);

/* _Checksum_CheckAreaByteXor: byte xor checksum of multiple mem areas */
_CheckSum1ByteType _Checksum_CheckAreasByteXor(const struct __ChecksumArea * areas,int num);

/* _Checksum_CheckAreaWordXor: word xor checksum of multiple mem areas */
_CheckSum2ByteType _Checksum_CheckAreasWordXor(const struct __ChecksumArea * areas,int num);

/* _Checksum_CheckAreaLongXor: long xor checksum of multiple mem areas */
_CheckSum4ByteType _Checksum_CheckAreasLongXor(const struct __ChecksumArea * areas,int num);


#endif /* _CHECKSUM_H_ */

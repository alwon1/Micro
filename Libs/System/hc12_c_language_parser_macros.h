/* Metrowerks Code Completion Support for HC12
 * Copyright © 2002-2005 Metrowerks Corporation.  All rights reserved.
 *
 * This header file is intended to be used by the CodeWarrior IDE
 * builtin language parser as macro file.
 * by default, projects are using the compiler to generate the browser
 * information and this file is not used therefore.
 * However if in the project settings, Build Extras
 * the Language Parser is enabled, this file can be used to get a more
 * accurate parsing by defining the same macros as the compiler 
 * defines internally.
 * However because many macros do depend on the actual settings,
 * some defines here may not be actuate.
 * To get a 100% accurate file, use the compiler option -Ldf to 
 * create a file specific to your setup.
 *
 * This file is not intended to be compiled with the target compiler to generate code.
 */


#ifndef __LINE__                         /* preprocessor defines */
#define __LINE__ 1                       /* always defined */
#define  __FILE__ "file"                 /* always defined */
#define __DATE__  "date"                 /* always defined */
#define __TIME__  "time"                 /* always defined */
#endif

#define __HIWARE__                       /* always defined */
#define __BIG_ENDIAN__                   /* always defined */
#define __HC12__                         /* always defined */
#define __PRODUCT_HICROSS_PLUS__         /* always defined */

#define __STDC__ 0                       /* default, maybe 1 with option -ansi */
#define __VERSION__ 5029                 /* always defined (maybe higher in later compilers) */
#define __VERSION_STR__ "V-5.0.29"       /* always defined (maybe higher in later compilers) */
#define __MWERKS__ 1                     /* always defined */
#define __BITFIELD_LSBIT_FIRST__         /* default, configurable  */
#define __BITFIELD_MSBYTE_FIRST__        /* default, configurable  */
#define __BITFIELD_MSWORD_FIRST__        /* default, configurable  */
#define __BITFIELD_TYPE_SIZE_REDUCTION__ /* default, configurable  */

#if 0 /* these depend on the memory model, cpu and others. Better no browse information than wrong one. */
#define __PTR_SIZE_2__                   /* depends on memory model */
#define __DIRECT_ADR__ 0                 /* depends on special option */
#define __SMALL__                        /* default, depends on the memory model -ms, -mb or -ml */
#define __NO_DPAGE__                     /* depend on -cpu, memory models, -cp */
#define __DPAGE_ADR__ 0x0034             /* depend on -cpu, memory models, -cp */
#define __NO_PPAGE__                     /* depend on -cpu, memory models, -cp */
#define __PPAGE_ADR__ 0x0035             /* depend on -cpu, memory models, -cp */
#define __NO_EPAGE__                     /* depend on -cpu, memory models, -cp */
#define __EPAGE_ADR__ 0x0036             /* depend on -cpu, memory models, -cp */
#define __NO_GPAGE__                     /* depend on -cpu, memory models, -cp */
#define __GPAGE_ADR__ 0x0010             /* depend on -cpu, memory models, -cp */
#define __NO_RPAGE__                     /* depend on -cpu, memory models, -cp */
#define __RPAGE_ADR__ 0x0016             /* depend on -cpu, memory models, -cp */
#define __DOUBLE_IS_IEEE32__             /* default, configurable with -T, -cf */
#define __LONG_DOUBLE_IS_IEEE32__        /* default, configurable with -T, -cf */
#define __LONG_LONG_DOUBLE_IS_IEEE32__   /* default, configurable with -T, -cf */
#define __OPTIMIZE_FOR_SIZE__            /* default, with -ot __OPTIMIZE_FOR_TIME__ */
#define __cplusplus						1          /* defined for -cppf */
#endif

/* these are correct for almost all users. But not for all as they depend on some options */
#define __STDC__ 0                       /* unless -ansi is specified */
#define __FLOAT_IS_IEEE32__              /* default, configurable with -T */
#define __CHAR_IS_SIGNED__               /* default, configurable with -T */
#define __CHAR_IS_8BIT__                 /* default, configurable with -T */
#define __SHORT_IS_16BIT__               /* default, configurable with -T */
#define __INT_IS_16BIT__                 /* default, configurable with -T */
#define __ENUM_IS_16BIT__                /* default, configurable with -T */
#define __LONG_IS_32BIT__                /* default, configurable with -T */
#define __LONG_LONG_IS_32BIT__           /* default, configurable with -T */
#define __SIZE_T_IS_UINT__               /* default. configurable? */
#define __PTRDIFF_T_IS_INT__             /* default. configurable? */
#define __ENUM_IS_SIGNED__               /* default, configurable with -T */
#define __VTAB_DELTA_IS_16BIT__          /* default. configurable? */
#define __WCHAR_T_IS_UCHAR__             /* default. configurable? */
#define __PTRMBR_OFFSET_IS_16BIT__       /* default. configurable? */
#define __PLAIN_BITFIELD_IS_SIGNED__     /* default, configurable with -T */
#define __ELF_OBJECT_FILE_FORMAT__       /* default, with -fh: __HIWARE_OBJECT_FILE_FORMAT__ */
#define __NOT_PROCESSOR_X4__             /* old compatibility macro only */


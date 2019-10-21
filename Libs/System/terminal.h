/******************************************************/
/**
* @file terminal.h
* Terminal: terminal high level functions.
* This module is using terminal low level functions (TERMIO_),
* so before using it, make sure you call TERMIO_Init().
*/
/*----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/
#ifndef TERMINAL_H
#define TERMINAL_H

#include <hidef.h>
#include <libdefs.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* Reads a single character from the terminal.
* @return Character received from the terminal.
*/   
char TERM_Read(void);

/**
* Reads a string from the terminal.
* As a side effect, each character read will be written as well (echo functionality).
* The backspace and delete characters are supported as well.
* Any non-printable character (apart of delete and backspace) will cause the function to return.
* @param str Pointer to the receive buffer.
* @param maxLen Size of the receive buffer. 
*/   
void TERM_ReadString(LIBDEF_StringPtr str, int maxLen);

/**
* Writes a single character to the terminal.
* @param ch Character to write.
*/   
void TERM_Write(char ch);

/**
* Writes a new-line to the terminal.
*/   
void TERM_WriteLn(void);

/**
* Writes a zero terminated string to the terminal.
* @param str Zero terminated string to be written.
*/   
void TERM_WriteString(LIBDEF_ConstStringPtr str);

/**
* Modes for terminal redirection.
* The modes can be set with TERM_Direct(). With this, terminal input/output can be either the
* the terminal window in the debugger or a file.
*/
typedef enum {
  TERM_TO_WINDOW   = 1, /**< Send output to terminal window only. */
  TERM_TO_BOTH     = 2, /**< Send output to file and window. */
  TERM_TO_FILE     = 3, /**< Send output to file 'fileName' only. */
  TERM_FROM_KEYS   = 4, /**< Read from keyboard. */
  TERM_FROM_FILE   = 5, /**< Read input from file 'fileName'. */
  TERM_APPEND_BOTH = 6, /**< Append output to file and window. */
  TERM_APPEND_FILE = 7  /**< Append output to file 'fileName' only. */
} TERM_DirectKind;

/**
* Sets the direction for the terminal, used for redirecting terminal input/output.
* The function checks if the argument 'what' is a legal one (see TERM_DirectKind).
* @param what Direction to be used.
* @param fileName File name if what direction is used together with a file. This argument is ignored
*                 if argument 'what' is TERM_TO_WINDOW or TERM_FROM_KEYS.
*/   
void TERM_Direct(TERM_DirectKind what, LIBDEF_ConstStringPtr fileName);

#ifdef __cplusplus
}
#endif

#endif


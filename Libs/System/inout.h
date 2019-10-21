/*****************************************************
   inout.h - Terminal: basic I/O functions.
   ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/
#ifndef INOUT_H
#define INOUT_H

#ifdef __cplusplus
extern "C" {
#endif

int INOUT_ReadInt(void);
  /* reads an integer value from the terminal */
int INOUT_TermChar(void);
  /* returns the last character read from the terminal */
void INOUT_WriteInt(int val);
  /* writes an integer value to the terminal */
void INOUT_WriteLong(long val);
  /* writes a long value to the terminal */

#ifdef __cplusplus
}
#endif

#endif


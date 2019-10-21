/******************************************************/
/**
* @file termio.h
* Terminal: terminal low level functions.
* Note that the low level functionality is depending on
* the hardware used (see implementation module termio.c),
* especially TERMIO_Init(). The provided implementation
* works in the simulator (component Terminal), but as
* well on most hardware.
*/
/*----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#ifndef TERMIO_H
#define TERMIO_H

#ifdef __cplusplus
extern "C" {
#endif


/**
* Sends a character to the terminal channel.
* @param ch Character to be sent to the terminal channel.
*/   
void TERMIO_PutChar(char ch);

/**
* Receives a character from the terminal channel.
* @return The character received from the terminal channel.
*/   
char TERMIO_GetChar(void);

/**
* Initializes the communication channel.
* It sets up the baudrate as well. Note that the implementation is
* heavily depending on the hardware used.
*/   
void TERMIO_Init(void);

#ifdef _TERMIO_HAS_PUT_STRING_
/**
* Writes a string at once (more efficient).
* @param p Pointer to the string to be written.
*/   
void TERMIO_PutString(const char *p);
#endif

#ifdef __cplusplus
}
#endif

#endif


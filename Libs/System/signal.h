/*****************************************************
    signal.h - ANSI-C library: exception handling
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/
  
#ifndef _H_SIGNAL_
#define _H_SIGNAL_

#ifdef __cplusplus
extern "C" {
#endif

#define SIG_IGN (void (*)())0
#define SIG_DFL (void (*)())1
#define SIG_ERR (void (*)())2

typedef void (*_sig_func) (void);
#if (defined(__M68K__) || defined(__HC16__)) 
  typedef int sig_atomic_t;
#else
  typedef char sig_atomic_t;
#endif

/**** Insert vector numbers of your target */
#define SIGINT   2
#define SIGFPE   8
#define SIGILL   4
#define SIGSEGV 11
#define SIGTERM 15
#define SIGABRT 22
#define SIGALRM 23

extern _sig_func signal (int sig, _sig_func func);
extern int       raise  (int sig);

#ifdef __cplusplus
}
#endif

#endif

/*****************************************************/
/* end signal.h */

/*****************************************************

     trace.cpp - ANSI-C++ library: Trace
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               
                  Do not modify!
 *****************************************************/

#ifndef trace_h
#define trace_h 1

#ifdef TRACE
#define T(X) X
#else
#define T(X)
#endif

class Trace
{
private:
  static int nesting;
  char *name;
public:
  Trace (char *n) {
#ifndef _C_LIB_LIMIT_IMPL      
    fprintf (stderr, "%*scalling %s\n", 3 * nesting++, "", name = n);
#endif
  }
  ~Trace (void) {
#ifndef _C_LIB_LIMIT_IMPL      
    fprintf (stderr, "%*sleaving %s\n", 3 * --nesting, "", name);
#endif
  }
};

#endif


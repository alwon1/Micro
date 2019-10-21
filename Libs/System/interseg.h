#ifndef __INTERSEG_CC__

#ifdef __ST19X__
#define __INTERSEG_CC__  __paged  __namemangle
#elif defined(__HC12__) 
#define __INTERSEG_CC__  __far  __namemangle
#else  /* __ST19X__ */
#define __INTERSEG_CC__  __namemangle
#endif /* __ST19X__ */

#endif /* __INTERSEG_CC__ */


#ifndef __NON_INTERSEG_CC__

#ifdef __ST19X__
#define __NON_INTERSEG_CC__  __far  __namemangle
#elif defined(__HC12__) 
#define __NON_INTERSEG_CC__  __near  __namemangle
#else /* __ST19X__ */
#define __NON_INTERSEG_CC__  __namemangle
#endif /* __ST19X__ */

#endif  /* __NON_INTERSEG_CC__ */

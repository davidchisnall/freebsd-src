/*
 * memmove is implemented in memcpy.S. Having this file simplifies the build
 * as it stops MISRCS from picking up the C implementation and rtld expects
 * to copy the memmove object file into its object directory.
 */

/*
 * If we're building with snmalloc's memcpy, we need to provide our own memmove.
 */
#ifdef SNMALLOC_MEMCPY
#define	__memmove_aarch64	memmove
#include "aarch64/memcpy.S"
#endif

#if !defined(SIMDE__SSE2_H)
#define SIMDE__SSE2_H

#define SIMDE__SSE2_INLINE_FUNC __attribute__((__always_inline__)) static inline

#if !defined(SIMDE__TYPE)
#  define SIMDE__TYPE(name) simde_simd__sse2_##name
#  define SIMDE__SYMBOL(name) simde_simd__sse2_##name
#endif

#include "sse.h"

#if defined(SIMDE__SSE2_NATIVE)
#  include <emmintrin.h>
#else

#include <stdint.h>
#include <limits.h>

typedef union {
  char           i8  __attribute__((__vector_size__(16)));
  short          i16 __attribute__((__vector_size__(16)));
  int            i32 __attribute__((__vector_size__(16)));
  unsigned char  u8  __attribute__((__vector_size__(16)));
  unsigned short u16 __attribute__((__vector_size__(16)));
  unsigned int   u32 __attribute__((__vector_size__(16)));
  float          flt __attribute__((__vector_size__(16)));
} SIMDE__TYPE(__m128i);
#if defined(__m128i)
#  undef __m128i
#endif
#define __m128i SIMDE__TYPE(__m128i)

SIMDE__SSE2_INLINE_FUNC
SIMDE__TYPE(__m128i)
SIMDE__SYMBOL(__mm_add_epi8) (__m128i a, __m128i b) {
  return (SIMDE__TYPE(__m128i)) { .i8 = a.i8 + b.i8 };
}
#if defined(_mm_add_epi8)
#  undef _mm_add_epi8
#endif
#define _mm_add_epi8 SIMDE__SYMBOL(__mm_add_epi8)

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(__m128i)
SIMDE__SYMBOL(__mm_set_epi8) (char e15, char e14, char e13, char e12,
			      char e11, char e10, char  e9, char  e8,
			      char  e7, char  e6, char  e5, char  e4,
			      char  e3, char  e2, char  e1, char  e0) {
  return (SIMDE__TYPE(__m128i)) { .i8 = {  e0,  e1,  e2,  e3,  e4,  e5,  e6,  e7,
					   e8,  e9, e10, e11, e12, e13, e14, e15 } };
}
#if defined(_mm_set_epi8)
#  undef _mm_set_epi8
#endif
#define _mm_set_epi8 SIMDE__SYMBOL(__mm_set_epi8)

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(__m128i)
SIMDE__SYMBOL(__mm_set_epi16) (short  e7, short  e6, short  e5, short  e4,
			       short  e3, short  e2, short  e1, short  e0) {
  return (SIMDE__TYPE(__m128i)) { .i16 = { e0, e1, e2, e3, e4, e5, e6, e7 } };
}
#if defined(_mm_set_epi16)
#  undef _mm_set_epi16
#endif
#define _mm_set_epi16 SIMDE__SYMBOL(__mm_set_epi16)

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(__m128i)
SIMDE__SYMBOL(__mm_set_epi32) (int  e3, int  e2, int  e1, int  e0) {
  return (SIMDE__TYPE(__m128i)) { .i32 = { e0, e1, e2, e3 } };
}
#if defined(_mm_set_epi32)
#  undef _mm_set_epi32
#endif
#define _mm_set_epi32 SIMDE__SYMBOL(__mm_set_epi32)

#endif /* !defined(SIMDE__SSE2_NATIVE) */
#endif /* !defined(SIMDE__SSE2_H) */
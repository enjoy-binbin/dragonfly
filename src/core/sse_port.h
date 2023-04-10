// Copyright 2023, DragonflyDB authors.  All rights reserved.
// See LICENSE for licensing terms.
//

#pragma once
#if defined(__aarch64__)
#include "base/sse2neon.h"
#else
#include <emmintrin.h>
#include <tmmintrin.h>
#endif

namespace dfly {

inline __m128i mm_loadu_si128(const __m128i* ptr) {
#if defined(__aarch64__)
  __m128i res;
  memcpy(&res, ptr, sizeof(res));
  return res;
// return vreinterpretq_m128i_s32(vld1q_s32((const int32_t *) p));
#else
  return _mm_loadu_si128(ptr);
#endif
}

}  // namespace dfly

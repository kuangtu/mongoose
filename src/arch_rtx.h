#pragma once

#if MG_ARCH == MG_ARCH_ARMCC || MG_ARCH == MG_ARCH_RTX

#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define strdup(s) ((char *) mg_strdup(mg_str(s)).ptr)

#if defined(__ARMCC_VERSION)
#define mode_t size_t
#define mkdir(a, b) mg_mkdir(a, b)
static inline int mg_mkdir(const char *path, mode_t mode) {
  (void) path, (void) mode;
  return -1;
}
#endif

#if MG_ARCH == MG_ARCH_RTX && !defined MG_ENABLE_RL && \
    (!defined(MG_ENABLE_LWIP) || !MG_ENABLE_LWIP) &&   \
    (!defined(MG_ENABLE_TCPIP) || !MG_ENABLE_TCPIP)
#define MG_ENABLE_RL 1
#endif

#endif

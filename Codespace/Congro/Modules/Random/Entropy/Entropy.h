#pragma once

#include "Entropy.space"
#include "Pool/Pool.h"
#include "../../../Core/Preprocessor/Detect/OperationSystem.h"

#include <errno.h>
#include <stdint.h>
#include <time.h>

#if OS_WINDOWS
#include <windows.h>
#include <bcrypt.h>
#if defined(_MSC_VER)
#pragma comment(lib, "bcrypt.lib")
#endif
#elif OS_LINUX
#include <sys/random.h>
#elif OS_MAC || OS_FREEBSD
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>
#endif

inline static bool RANDOM_ENTROPY_FUNC(System)(void *destination, size_t size);
inline static uint64_t RANDOM_ENTROPY_FUNC(Address)(void);
inline static uint64_t RANDOM_ENTROPY_FUNC(Clock)(void);
inline static uint64_t RANDOM_ENTROPY_FUNC(Jitter)(void);
inline static uint64_t RANDOM_ENTROPY_FUNC(Thread)(void);
inline static uint64_t RANDOM_ENTROPY_FUNC(Time)(void);
inline static uint64_t RANDOM_ENTROPY_FUNC(Collect)(void);

#include "Impl/Entropy.impl"

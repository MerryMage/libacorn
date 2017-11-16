// Copyright (c) 2017 libacorn project
// This software may be freely distributed under the MIT license.
// Please refer to the LICENSE file included for details.

#include <cstddef>
#include <sys/mman.h>

#include "libacorn/util/memory_util.hpp"

namespace libacorn {
namespace util {

void* AllocateExecutableMemory(std::size_t size) {
    void* ret = mmap(nullptr, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, -1, 0);
    return ret == MAP_FAILED ? nullptr : ret;
}

} // namespace util
} // namespace libacorn

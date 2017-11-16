// Copyright (c) 2017 libacorn project
// This software may be freely distributed under the MIT license.
// Please refer to the LICENSE file included for details.

#include <cstring>

#include <catch.hpp>

#include "libacorn/util/memory_util.hpp"

TEST_CASE("can allocate executable memory") {
    // code():
    //   mov w0, 42
    //   ret
    const char code[] = "\x40\x05\x80\x52\xc0\x03\x5f\xd6";

    void* mem = libacorn::util::AllocateExecutableMemory(1024);
    std::memcpy(mem, code, sizeof(code));

    auto fn = reinterpret_cast<int(*)()>(mem);
    REQUIRE(fn() == 42);
}

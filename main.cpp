#pragma GCC optimize("-O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")

#include "config/config.h"

#include <iostream>

#include "util/my_assert.h"

#include "simulation/world/World.h"
#include "tests/tests.h"
#include "benchmarks/benchmarks.h"

using namespace std;

int main() {
#ifdef RUN_TESTS
    DO_RUN_TESTS();
#endif
#ifdef RUN_BENCHMARKS
    DO_RUN_BENCHMARKS();
#endif

  //  World w;
    return 0;
}
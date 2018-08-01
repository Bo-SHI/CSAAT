#ifndef __NOTE_UNIQUE_H__
#define __NOTE_UNIQUE_H__

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

namespace Note {

// Init random seed on program startup
namespace detail {
    static class initializer {
    public:
        initializer() { srand((unsigned int)time(NULL)); }
    } _init;
}

inline int randInt(int from, int to) {
    return from + rand() % (to - from);
}

inline int randDigits(int n) {
    static const int maxIntDigits = (int)log10(INT_MAX);
    assert(n > 0 && n < maxIntDigits);
    int base = 1;
    for (int i = 0; i < n-1; ++i) {
        base *= 10;
    }

    return randInt(base, base*10);
}

};

#endif

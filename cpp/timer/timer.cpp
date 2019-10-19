// c
// 时间相关
#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

static uint64_t gettime() {
    uint64_t t;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    t = (uint64_t)tv.tv_sec * 100;
    t += tv.tv_usec / 10000;
    return t;
}

int main() {
    printf("t : %ld\n", gettime());
    return 0;
}

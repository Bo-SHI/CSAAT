#include "apue.h"

static void m_exit1(void);
static void m_exit2(void);

int main(int argc, char *argv[]) {
    if (atexit(m_exit2) != 0) {
        err_sys("cant register m_exit2");
    }
    if (atexit(m_exit1) != 0) {
        err_sys("cant register m_exit1");
    }
    if (atexit(m_exit1) != 0) {
        err_sys("cant register m_exit1");
    }

    printf("main process is done\n");
    //return 0;
    exit(0);
}

static void m_exit1() {
    printf("first exit handler\n");
}

static void m_exit2() {
    printf("second exit handler\n");
}


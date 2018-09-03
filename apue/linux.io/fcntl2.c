#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        err_quit("Usage: a.out <descriptor$>");
    }
    int val;
    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) == -1) {
        err_quit("fcntl() error for %d", atoi(argv[1]));
    }
    val |= O_RDWR;
    if (fcntl(atoi(argv[1]), F_SETFL, val) < 0) {
        err_quit("fcntl() error");
    }

    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) == -1) {
        err_quit("fcntl() error for %d", atoi(argv[1]));
    }
    if ((val&O_ACCMODE) == O_RDWR) {
        printf("true");
    }
    putchar('\n');
    return 0;
}

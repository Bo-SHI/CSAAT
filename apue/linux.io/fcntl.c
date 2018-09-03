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

    switch(val & O_ACCMODE) {
        case O_RDONLY:
            printf("read only");
            break;
        case O_WRONLY:
            printf("write only");
            break;
        case O_RDWR:
            printf("read write");
            break;
        default:
            printf("unknown access mode");
    }

    printf("\n");

    return 0;
}

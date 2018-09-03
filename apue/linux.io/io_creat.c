#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void error(const char *err);
int main(int argc, char *argv[]) {
    int fd;
    if ((fd = open("file", O_CREAT | O_EXCL)) == -1) {
        error("open() error");
    }
    return 0;
}

void error(const char *err) {
    printf("%s\n", err);
    exit(1);
}

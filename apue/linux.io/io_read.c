#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUFFSIZE 4096

void error(const char *msg);

int main(int argc, char *argv[]) {
    int fd = open("eg.file.txt", O_RDONLY);
    if (-1 == fd) {
        error("open() error");
    }

    if (-1 == lseek(fd, 0, SEEK_SET)) {
        error("lseek() error");
    }

    int n;
    char buff[BUFFSIZE];
    while ((n = read(fd, buff, sizeof buff)) > 0) {
        if ((write(STDOUT_FILENO, buff, n)) != n) {
            error("write error");
        }
    }

    if (n < 0) {
        error("read error");
    }

    // 进程结束的时候会自动关闭所有的文件描述符
    // 明确关闭
    close(fd);
    return 0;
}

void error(const char* msg) {
    printf("%s\n", msg);
    exit(1);
}

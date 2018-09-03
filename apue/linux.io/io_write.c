#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd = open("open.txt", O_CREAT | O_WRONLY);
    if (-1 == fd) {
        printf("open() file failed\n");
        exit(0);
    } else {
        printf("File Descriptor: %d\n", fd);
    }

    if (-1 == lseek(fd, 0, SEEK_SET)) {
        printf("lseek() file failed!\n");
        exit(0);
    }

    char msg[] = "hello world\n!";
    size_t size = sizeof(msg);
    printf("prepare write %d bytes to file...\n", (int)size);

    if (write(fd, msg, size) != size) {
        printf("write() failed!\n");
    } else {
        printf("write() successed!\n");
    }
    close(fd);

    return 0;
}

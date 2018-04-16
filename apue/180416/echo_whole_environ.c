#include "apue.h"

extern char **environ;

int main(int argc, char *argv[]) {
    int i = 0;
    char *ep = environ[i];
    while (ep) {
        printf("%s\n", ep);

        ++i;
        ep = environ[i];
    }

    exit(0);
}

#include "apue.h"

int global_var = 10;
char buf[] = "a write to stdout\n";

int main(int argc, char *argv[]) {
    int var;
    pid_t pid;

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1) {
        err_sys("write error");
    }
    printf("before fork:\n");

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        // Chlid Process
        global_var++;
        var++;
    } else {
        // Parent Process
        sleep(2);
    }

    printf("pid=%ld, global_var=%d, var=%d\n", (long)getpid(), global_var, var);

    return 0;
}

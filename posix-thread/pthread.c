#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

void *thread_function(void*);

int main() {
    pid_t pid;
    pthread_t tid;
    if (0 != pthread_create(&tid, NULL, thread_function, NULL)) {
        printf("new thread failed\n");
        return 0;
    }

    pthread_join(tid, NULL);

    // 打印线程ID
    printf("process Id: %d, main thread number: %ld\n", getpid(), pthread_self());
    return 0;
}

void *thread_function(void* arg) {
    printf("porcess Id: %d, new thread number: %ld\n", getpid(), pthread_self());
    // 进程中任意线程调用 exit
    exit(0);
}

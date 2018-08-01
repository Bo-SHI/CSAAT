#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *func(void*);

int counter = 0;

int main(int argc, char *argv[]) {
    pthread_t t1, t2;
    char *msg1 = "Thread1";
    char *msg2 = "Thread2";
    int iret1, iret2;

    if (iret1 = pthread_create(&t1, NULL, func, (void*)msg1)) {
        printf("create thread 1 failed\n");
    }

    if (iret2 = pthread_create(&t2, NULL, func, (void*)msg2)) {
        printf("create thread 2 failed\n");
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

void *func(void *arg) {
    pthread_mutex_lock(&mutex);
    counter++;
    printf("Counter value: %d\n", counter);
    pthread_mutex_unlock(&mutex);
}

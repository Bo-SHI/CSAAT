#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 10
void *thread_func(void*);
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

int main(int argc, char *argv[]) {
    pthread_t threads[NTHREADS];
    int i, j;
    for (i = 0; i < NTHREADS; ++i) {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }
    for (j = 0; j < NTHREADS; ++j) {
        pthread_join(threads[j], NULL);
    }

    printf("Final counter value: %d\n", counter);
}

void *thread_func(void *arg) {
    printf("Thread Id: %ld\n", pthread_self());
    pthread_mutex_lock(&mutex);
    counter++;
    pthread_mutex_unlock(&mutex);
}

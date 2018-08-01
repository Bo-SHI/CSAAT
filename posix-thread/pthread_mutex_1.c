#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>

struct Foo {
    int id;

    int count;
    pthread_mutex_t mutex;
};

struct Foo* create(int id) {
    struct Foo* fp;
    if ((fp = malloc(sizeof(struct Foo))) != NULL) {
        fp->id = id;
        fp->count = 1;
        if (0 != pthread_mutex_init(&fp->mutex, NULL) ){
            free(fp);
            return NULL;
        }
        // TODO
    }

    return fp;
}

void foo_hold(struct Foo *fp) {
    pthread_mutex_lock(&fp->mutex);
    fp->count++;
    pthread_mutex_unlock(&fp->mutex);
}

void foo_rele(struct Foo *fp) {
    pthread_mutex_lock(&fp->mutex);
    if (0 == --fp->count) {
        printf("destroy success\n");
        pthread_mutex_unlock(&fp->mutex);
        pthread_mutex_destroy(&fp->mutex);
        free(fp);
    } else {
        pthread_mutex_unlock(&fp->mutex);
    }
}

void *thread_func(void *);

int main(int argc, char *argv[]) {
    struct Foo *fp = create(1);
    if (NULL == fp) {
        printf("create Foo failed\n");
        exit(0);
    }

    printf("main thread count: %d\n", fp->count);

    pthread_t tid1;
    if (0 != pthread_create(&tid1, NULL, thread_func, (void*)fp)) {
        printf("new thread 1 failed\n");
        exit(0);
    }

    if (0 != pthread_join(tid1, NULL)) {
        printf("cannt join with tid1\n");
        exit(0);
    }

    foo_rele(fp);

    exit(0);
}

void *thread_func(void *arg) {
    struct Foo *fp = (struct Foo*)arg;
    foo_hold(fp);
    printf("thread 1, count: %d\n", fp->count);
    foo_rele(fp);
    pthread_exit((void*)0);
}

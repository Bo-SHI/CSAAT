#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>

struct Foo {
    int a, b, c, d;
};

void print(const char *s, const struct Foo *fp) {
    printf("%s", s);
    printf(" structure at 0x%lx\n", (unsigned long)fp);
    printf(" foo.a = %d\n", fp->a);
    printf(" foo.b = %d\n", fp->b);
    printf(" foo.c = %d\n", fp->c);
    printf(" foo.d = %d\n", fp->d);
}

void *thread_function_1(void *arg) {
    struct Foo foo = {1, 2, 3, 4};

    print("thread 1:\n", &foo);
    pthread_exit((void*)&foo);
}

void *thread_function_2(void *arg) {
    printf("thread 2: Id is %lu\n", (unsigned long)pthread_self());
    pthread_exit((void*)0);
}

int main(int argc, char *argv[]) {
    pthread_t tid1, tid2;
    struct Foo *fp;
    if (0 != pthread_create(&tid1, NULL, thread_function_1, NULL)) {
        printf("new thread 1 failed\n");
        exit(0);
    }
    if (0 != pthread_join(tid1, (void*)&fp)) {
        printf("cannt join with thread 1\n");
        exit(0);
    }

    // if (0 != pthread_create(&tid2, NULL, thread_function_2, NULL)) {
    //     printf("new thread 2 failed\n");
    //     exit(0);
    // }
    // if (0 != pthread_join(tid2, NULL)) {
    //     printf("cannt join with thread 2\n");
    //     exit(0);
    // }

    print("main thread: \n", fp);

    return 0;
}

#include <pthrad.h>

#include <stdio.h>
#include <stdlib.h>

#define NHASH 29
#define HASH(id) (((unsigned long)id) % NHSAH)

struct Foo *fh[NHASH];

pthread_mutex_t hashMutex = PTHREAD_MUTEX_INITIALIZER;

struct Foo {
    int count;
    pthread_mutex_t mutex;
    int id;
    struct Foo *next;
};

struct Foo* create(int id) {
    struct Foo *fp;
    int idx;

    if ((fp = malloc(sizeof(struct Foo))) != NULL) {
        fp->count = 1;
        fp->id = id;
        if (0 != pthread_mutex_init(&fp->mutex, NULL)) {
            free(fp);
            return NULL;
        }
        idx = HASH(id);
        pthread_mutex_lock(&hashMutex);
        fp->next = fh[idx];
        fh[idx] = fp;
        pthread_mutex_lock(&fp->mutex);
        pthread_mutex_unlock(&hashMutex);
        // TODO
        pthread_mutex_unlock(&fp->mutex);
    }

    return fp;
}

void hold(struct Foo *fp) {
    pthread_mutex_lock(&fp->mutex);
    fp->cout++;
    pthread_mutex_unlock(&fp->mutex);
}

struct Foo* find(int id) {
    struct Foo *fp;

    pthread_mutex_lock(&hashMutex);
    for (fp = fh[HASH(id)]; fp != NULL; fp = fp->next) {
        if (fp->id = id) {
            hold(fp);
            break;
        }
    }
    pthread_mutex_unlock(&hashMutex);

    return fp;
}

void rele(struct Foo *fp) {
    struct Foo *tfp;
    int idx;

    pthread_mutex_lock(&fp->mutex);
    if (fp->count == 1) {
        pthread_mutex_unlock(&fp->mutex);
        pthread_mutex_lock(&hashMutex);
        pthread_mutex_lock(&fp->mutex);
        if (fp->count != 1) {
            fp->count--;
            pthread_mutex_unlock(&fp->mutex);
            pthread_mutex_unlock(&hashMutex);
            return;
        }
        idx = HASH(fp->id);
        tfp = fh[idx];
        if (tfp == fp) {
            fh[idx] = fp->next;
        } else {
            while (tfp->next != fp) {
                tfp = tfp->next;
            }
            tfp->next = fp->next;
        }
        pthread_mutex_unlock(&hashMutex);
        pthread_mutex_unlock(&fp->mutex);
        pthread_mutex_destroy(&fp->mutex);
        free(fp);
    } else {
        fp->count--;
        pthread_mutex_unlock(&fp->mutex);
    }
}

int main(int argc, char *argv[]) {
    // TODO
    return 0;
}

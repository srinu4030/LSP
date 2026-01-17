//Write a C program to implement a reader-writer lock using pthreads. Create multiple
//reader threads and writer threads and ensure proper synchronization using the reader-writer lock?

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int sharedData = 0;
pthread_rwlock_t rwlock;

void *reader(void *arg)
{
    int id = *(int *)arg;
    pthread_rwlock_rdlock(&rwlock);
    printf("Reader %d reads: %d\n", id, sharedData);
    pthread_rwlock_unlock(&rwlock);
    return NULL;
}

void *writer(void *arg)
{
    int id = *(int *)arg;
    pthread_rwlock_wrlock(&rwlock);
    sharedData += 10;
    printf("Writer %d updates value to %d\n", id, sharedData);
    pthread_rwlock_unlock(&rwlock);
    return NULL;
}

int main()
{
    pthread_t r1, r2, w1;
    int id1=1, id2=2, idw=1;

    pthread_rwlock_init(&rwlock, NULL);

    pthread_create(&r1, NULL, reader, &id1);
    pthread_create(&w1, NULL, writer, &idw);
    pthread_create(&r2, NULL, reader, &id2);

    pthread_join(r1, NULL);
    pthread_join(w1, NULL);
    pthread_join(r2, NULL);

    pthread_rwlock_destroy(&rwlock);
    return 0;
}


//Implement a C program to create two threads that increment and decrement a shared variable, respectively, using mutex locks?

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
int shared = 0;

void *increment(void *arg)
{
    pthread_mutex_lock(&lock);
    shared++;
    printf("Incremented value: %d\n", shared);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *decrement(void *arg)
{
    pthread_mutex_lock(&lock);
    shared--;
    printf("Decremented value: %d\n", shared);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, decrement, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}


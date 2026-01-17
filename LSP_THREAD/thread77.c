//Write a C program to create two threads that increment and decrement a shared variable, respectively, using mutex locks?

#include <stdio.h>
#include <pthread.h>

int sharedVar = 0;
pthread_mutex_t lock;

void *increment(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&lock);
        sharedVar++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void *decrement(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&lock);
        sharedVar--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main()
{
    pthread_t tid1, tid2;

    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Create threads
    pthread_create(&tid1, NULL, increment, NULL);
    pthread_create(&tid2, NULL, decrement, NULL);

    // Wait for threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Final value of shared variable = %d\n", sharedVar);

    // Destroy mutex
    pthread_mutex_destroy(&lock);

    return 0;
}


//Write a C program to demonstrate thread synchronization using mutex locks. Create two
//threads that increment a shared variable using mutex locks to ensure proper synchronization?

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

int main()
{
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final value of shared variable = %d\n", sharedVar);

    pthread_mutex_destroy(&lock);
    return 0;
}


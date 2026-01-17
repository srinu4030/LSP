//Develop a C program to create two threads that print their thread IDs and synchronize their output?

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void *printThreadID(void *arg)
{
    pthread_mutex_lock(&lock);
    printf("Thread ID: %lu\n", (unsigned long)pthread_self());
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, printThreadID, NULL);
    pthread_create(&t2, NULL, printThreadID, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}


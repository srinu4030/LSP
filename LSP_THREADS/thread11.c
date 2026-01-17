//Write a C program to create a thread that prints "Hello, World!" with thread synchronization?

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void *printHello(void *arg)
{
    pthread_mutex_lock(&lock);
    printf("Hello, World!\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t tid;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&tid, NULL, printHello, NULL);
    pthread_join(tid, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}


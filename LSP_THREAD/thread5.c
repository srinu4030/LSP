//Write a C program to create two threads that print their thread IDs?


#include <stdio.h>
#include <pthread.h>

void *printThreadID(void *arg)
{
    pthread_t tid = pthread_self();
    printf("Thread ID: %lu\n", (unsigned long)tid);
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, printThreadID, NULL);
    pthread_create(&t2, NULL, printThreadID, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}


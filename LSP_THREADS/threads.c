//Write a C program to create a thread that prints "Hello, World!"?

#include <stdio.h>
#include <pthread.h>

void *printHello(void *arg)
{
    printf("Hello, World!\n");
    return NULL;
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, printHello, NULL);
    pthread_join(tid, NULL);

    return 0;
}


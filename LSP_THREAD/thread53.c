//Write a C program to create two threads using pthreads library. Each thread should print
//"Hello, World!" along with its thread ID?

#include <stdio.h>
#include <pthread.h>

void *printHello(void *arg)
{
    printf("Hello, World! Thread ID: %lu\n", (unsigned long)pthread_self());
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, printHello, NULL);
    pthread_create(&t2, NULL, printHello, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}


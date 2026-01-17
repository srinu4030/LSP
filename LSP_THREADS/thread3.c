//Develop a C program to create two threads that print numbers from 1 to 10 concurrently?

#include <stdio.h>
#include <pthread.h>

void *printNumbers(void *arg)
{
    int thread_id = *(int *)arg;

    for (int i = 1; i <= 10; i++)
    {
        printf("Thread %d: %d\n", thread_id, i);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_create(&t1, NULL, printNumbers, &id1);
    pthread_create(&t2, NULL, printNumbers, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}


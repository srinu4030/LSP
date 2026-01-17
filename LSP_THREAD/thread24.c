//Write a C program to create a thread that generates a random array of integers?


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

int arr[10];

void *generateRandom(void *arg)
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    return NULL;
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, generateRandom, NULL);
    pthread_join(tid, NULL);

    return 0;
}


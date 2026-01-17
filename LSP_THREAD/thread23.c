//Write a C program to create a thread that calculates the sum of squares of numbers from 1 to 100?

#include <stdio.h>
#include <pthread.h>

void *sumOfSquares(void *arg)
{
    int sum = 0;
    for (int i = 1; i <= 100; i++)
        sum += i * i;

    printf("Sum of squares (1 to 100) = %d\n", sum);
    return NULL;
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, sumOfSquares, NULL);
    pthread_join(tid, NULL);

    return 0;
}


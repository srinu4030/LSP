//Develop a C program to create a thread that calculates the average of numbers from 1 to 100?

#include <stdio.h>
#include <pthread.h>

void *calculateAverage(void *arg)
{
    int sum = 0;
    for (int i = 1; i <= 100; i++)
        sum += i;

    float avg = sum / 100.0;
    printf("Average of numbers from 1 to 100 = %.2f\n", avg);

    return NULL;
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, calculateAverage, NULL);
    pthread_join(tid, NULL);

    return 0;
}


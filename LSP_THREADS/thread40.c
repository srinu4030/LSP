//Develop a C program to create a thread that calculates the average of numbers in an array?

#include <stdio.h>
#include <pthread.h>

int arr[100], n;

void *calculateAverage(void *arg)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    printf("Average = %.2f\n", sum / (float)n);
    return NULL;
}

int main()
{
    pthread_t tid;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    pthread_create(&tid, NULL, calculateAverage, NULL);
    pthread_join(tid, NULL);

    return 0;
}


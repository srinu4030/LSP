//Develop a C program to create a thread that finds the maximum element in an array?

#include <stdio.h>
#include <pthread.h>

int arr[100], n;

void *findMax(void *arg)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    printf("Maximum element = %d\n", max);
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

    pthread_create(&tid, NULL, findMax, NULL);
    pthread_join(tid, NULL);

    return 0;
}


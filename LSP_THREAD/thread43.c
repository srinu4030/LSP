//Develop a C program to create a thread that calculates the sum of elements in an array?

#include <stdio.h>
#include <pthread.h>

int arr[100], n;

void *sumArray(void *arg)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    printf("Sum of array elements = %d\n", sum);
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

    pthread_create(&tid, NULL, sumArray, NULL);
    pthread_join(tid, NULL);

    return 0;
}


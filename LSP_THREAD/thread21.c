//Implement a C program to create a thread that performs selection sort on an array of integers?


#include <stdio.h>
#include <pthread.h>

int arr[100], n;

void *selectionSort(void *arg)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
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

    pthread_create(&tid, NULL, selectionSort, NULL);
    pthread_join(tid, NULL);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}


//Write a C program to create a thread that searches for a given number in an array?

#include <stdio.h>
#include <pthread.h>

int arr[100], n, key;

void *searchArray(void *arg)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("%d found at index %d\n", key, i);
            return NULL;
        }
    }
    printf("%d not found in array\n", key);
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

    printf("Enter number to search: ");
    scanf("%d", &key);

    pthread_create(&tid, NULL, searchArray, NULL);
    pthread_join(tid, NULL);

    return 0;
}


//Write a C program to create a thread that sorts an array of strings?

#include <stdio.h>
#include <pthread.h>
#include <string.h>

char arr[10][100];
int n;

void *sortStrings(void *arg)
{
    char temp[100];
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(arr[i], arr[j]) > 0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }

    printf("Sorted strings:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    return NULL;
}

int main()
{
    pthread_t tid;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings:\n");
    for (int i = 0; i < n; i++)
        scanf("%s", arr[i]);

    pthread_create(&tid, NULL, sortStrings, NULL);
    pthread_join(tid, NULL);

    return 0;
}


//Develop a C program to create a thread that prints the multiplication table of a given number up to a given limit?

#include <stdio.h>
#include <pthread.h>

typedef struct {
    int number;
    int limit;
} TableData;

void *printTable(void *arg)
{
    TableData *data = (TableData *)arg;
    printf("Multiplication Table of %d up to %d:\n", data->number, data->limit);
    for (int i = 1; i <= data->limit; i++)
    {
        printf("%d x %d = %d\n", data->number, i, data->number * i);
    }
    return NULL;
}

int main()
{
    pthread_t tid;
    TableData data;

    printf("Enter a number: ");
    scanf("%d", &data.number);

    printf("Enter limit: ");
    scanf("%d", &data.limit);

    // Create thread
    pthread_create(&tid, NULL, printTable, &data);

    // Wait for thread to finish
    pthread_join(tid, NULL);

    return 0;
}


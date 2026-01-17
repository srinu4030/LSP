//Implement a C program to create a thread that calculates the square of a number?

#include <stdio.h>
#include <pthread.h>

void *calculateSquare(void *arg)
{
    int num = *(int *)arg;
    int square = num * num;

    printf("Square of %d = %d\n", num, square);
    return NULL;
}

int main()
{
    pthread_t tid;
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    pthread_create(&tid, NULL, calculateSquare, &number);
    pthread_join(tid, NULL);

    return 0;
}


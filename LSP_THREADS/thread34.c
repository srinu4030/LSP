//Write a C program to create a thread that checks if a given number is a perfect square?

#include <stdio.h>
#include <pthread.h>
#include <math.h>

void *checkPerfectSquare(void *arg)
{
    int num = *(int *)arg;
    int root = sqrt(num);

    if (root * root == num)
        printf("%d is a Perfect Square\n", num);
    else
        printf("%d is NOT a Perfect Square\n", num);

    return NULL;
}

int main()
{
    pthread_t tid;
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    pthread_create(&tid, NULL, checkPerfectSquare, &number);
    pthread_join(tid, NULL);

    return 0;
}


//Implement a C program to create a thread that checks if a number is even or odd?

#include <stdio.h>
#include <pthread.h>

void *checkEvenOdd(void *arg)
{
    int num = *(int *)arg;
    if (num % 2 == 0)
        printf("%d is Even\n", num);
    else
        printf("%d is Odd\n", num);
    return NULL;
}

int main()
{
    pthread_t tid;
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    pthread_create(&tid, NULL, checkEvenOdd, &number);
    pthread_join(tid, NULL);

    return 0;
}


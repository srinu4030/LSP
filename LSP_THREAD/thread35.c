//Write a C program to create a thread that calculates the sum of digits of a given number?

#include <stdio.h>
#include <pthread.h>

void *sumOfDigits(void *arg)
{
    int num = *(int *)arg;
    int sum = 0;

    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }

    printf("Sum of digits = %d\n", sum);
    return NULL;
}

int main()
{
    pthread_t tid;
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    pthread_create(&tid, NULL, sumOfDigits, &number);
    pthread_join(tid, NULL);

    return 0;
}


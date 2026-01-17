//Develop a C program to create a thread that checks if a number is prime?

#include <stdio.h>
#include <pthread.h>

void *checkPrime(void *arg)
{
    int num = *(int *)arg;
    int isPrime = 1;

    if (num <= 1)
        isPrime = 0;

    for (int i = 2; i * i <= num && isPrime; i++)
    {
        if (num % i == 0)
            isPrime = 0;
    }

    if (isPrime)
        printf("%d is a Prime number\n", num);
    else
        printf("%d is NOT a Prime number\n", num);

    return NULL;
}

int main()
{
    pthread_t tid;
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    pthread_create(&tid, NULL, checkPrime, &number);
    pthread_join(tid, NULL);

    return 0;
}


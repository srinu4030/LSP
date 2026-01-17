//Write a C program to create a thread that calculates the factorial of numbers from 1 to 10?

#include <stdio.h>
#include <pthread.h>

void *factorial1to10(void *arg)
{
    for (int i = 1; i <= 10; i++)
    {
        long long fact = 1;
        for (int j = 1; j <= i; j++)
            fact *= j;
        printf("Factorial of %d = %lld\n", i, fact);
    }
    return NULL;
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, factorial1to10, NULL);
    pthread_join(tid, NULL);

    return 0;
}


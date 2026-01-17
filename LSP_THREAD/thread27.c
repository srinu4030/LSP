//Write a C program to create a thread that calculates the sum of Fibonacci numbers up to a given limit?

#include <stdio.h>
#include <pthread.h>

void *sumFibonacci(void *arg)
{
    int n = *(int *)arg;
    int a = 0, b = 1, sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += a;
        int next = a + b;
        a = b;
        b = next;
    }

    printf("Sum of Fibonacci numbers up to %d terms = %d\n", n, sum);
    return NULL;
}

int main()
{
    pthread_t tid;
    int limit;

    printf("Enter number of Fibonacci terms: ");
    scanf("%d", &limit);

    pthread_create(&tid, NULL, sumFibonacci, &limit);
    pthread_join(tid, NULL);

    return 0;
}


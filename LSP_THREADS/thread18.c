//Implement a C program to create a thread that calculates the sum of Fibonacci numbers up
//to a given limit using dynamic programming with mutex locks?

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
int limit;

void *sumFibonacci(void *arg)
{
    pthread_mutex_lock(&lock);

    int fib[100];
    fib[0] = 0;
    fib[1] = 1;
    int sum = fib[0] + fib[1];

    for (int i = 2; i < limit; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        sum += fib[i];
    }

    printf("Sum of Fibonacci numbers up to %d terms = %d\n", limit, sum);

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t tid;

    printf("Enter number of Fibonacci terms: ");
    scanf("%d", &limit);

    pthread_mutex_init(&lock, NULL);

    pthread_create(&tid, NULL, sumFibonacci, NULL);
    pthread_join(tid, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}


//Implement a C program to create a thread that prints prime numbers up to a given limit with mutex locks?

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
int limit;

int isPrime(int n)
{
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

void *printPrimes(void *arg)
{
    pthread_mutex_lock(&lock);

    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++)
        if (isPrime(i))
            printf("%d ", i);
    printf("\n");

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t tid;

    printf("Enter limit: ");
    scanf("%d", &limit);

    pthread_mutex_init(&lock, NULL);

    pthread_create(&tid, NULL, printPrimes, NULL);
    pthread_join(tid, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}


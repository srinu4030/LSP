//Implement a C program to create a thread that calculates the factorial of a given number?

#include <stdio.h>
#include <pthread.h>

void *factorial(void *arg)
{
    int n = *(int *)arg;
    long long fact = 1;

    for (int i = 1; i <= n; i++)
        fact *= i;

    printf("Factorial of %d = %lld\n", n, fact);

    return NULL;
}

int main()
{
    pthread_t tid;
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    pthread_create(&tid, NULL, factorial, &num);
    pthread_join(tid, NULL);

    return 0;
}


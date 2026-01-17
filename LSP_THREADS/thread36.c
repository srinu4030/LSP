//Implement a C program to create a thread that calculates the factorial of a given number using recursion?

#include <stdio.h>
#include <pthread.h>

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

void *factorialThread(void *arg)
{
    int n = *(int *)arg;
    printf("Factorial of %d = %d\n", n, factorial(n));
    return NULL;
}

int main()
{
    pthread_t tid;
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    pthread_create(&tid, NULL, factorialThread, &number);
    pthread_join(tid, NULL);

    return 0;
}


//Implement a C program to create a thread that calculates the square root of a number?

#include <stdio.h>
#include <pthread.h>
#include <math.h>

void *calculateSqrt(void *arg)
{
    double num = *(double *)arg;
    printf("Square root of %.2lf = %.2lf\n", num, sqrt(num));
    return NULL;
}

int main()
{
    pthread_t tid;
    double number;

    printf("Enter a number: ");
    scanf("%lf", &number);

    pthread_create(&tid, NULL, calculateSqrt, &number);
    pthread_join(tid, NULL);

    return 0;
}


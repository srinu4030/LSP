//Develop a C program to create a thread that calculates the greatest common divisor (GCD) of two numbers?

#include <stdio.h>
#include <pthread.h>

void *calculateGCD(void *arg)
{
    int *nums = (int *)arg;
    int a = nums[0];
    int b = nums[1];

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    printf("GCD = %d\n", a);
    return NULL;
}

int main()
{
    pthread_t tid;
    int numbers[2];

    printf("Enter two numbers: ");
    scanf("%d %d", &numbers[0], &numbers[1]);

    pthread_create(&tid, NULL, calculateGCD, numbers);
    pthread_join(tid, NULL);

    return 0;
}


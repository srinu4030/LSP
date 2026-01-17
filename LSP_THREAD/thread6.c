//Develop a C program to create a thread that prints the sum of two numbers?


#include <stdio.h>
#include <pthread.h>

void *printSum(void *arg)
{
    int *nums = (int *)arg;
    int sum = nums[0] + nums[1];

    printf("Sum = %d\n", sum);
    return NULL;
}

int main()
{
    pthread_t tid;
    int numbers[2];

    printf("Enter two numbers: ");
    scanf("%d %d", &numbers[0], &numbers[1]);

    pthread_create(&tid, NULL, printSum, numbers);
    pthread_join(tid, NULL);

    return 0;
}


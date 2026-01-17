//Write a C program to create a thread that performs addition of two numbers with mutex locks?


#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void *addNumbers(void *arg)
{
    int *nums = (int *)arg;

    pthread_mutex_lock(&lock);
    printf("Sum = %d\n", nums[0] + nums[1]);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t tid;
    int nums[2];

    printf("Enter two numbers: ");
    scanf("%d %d", &nums[0], &nums[1]);

    pthread_mutex_init(&lock, NULL);

    pthread_create(&tid, NULL, addNumbers, nums);
    pthread_join(tid, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}


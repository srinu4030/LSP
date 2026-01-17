//Write a C program to demonstrate thread cancellation. Create a thread that runs an infinite
//loop and cancels it after a certain condition is met from the main thread? 

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *infiniteThread(void *arg)
{
    while (1)
    {
        printf("Thread running...\n");
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, infiniteThread, NULL);
    sleep(5); // let the thread run for 5 seconds

    pthread_cancel(tid); // cancel the thread
    pthread_join(tid, NULL);

    printf("Thread cancelled.\n");
    return 0;
}


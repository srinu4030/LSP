//program to create multiple threads, each printing its own message?


#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 3

void *printMessage(void *arg)
{
    int thread_id = *(int *)arg;
    printf("Hello from Thread %d\n", thread_id);
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, printMessage, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}


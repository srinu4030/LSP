//Develop a C program to create a thread that prints numbers from 10 to 1 in descending order using mutex locks?

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void *printDescending(void *arg)
{
    pthread_mutex_lock(&lock); // Lock to ensure exclusive access
    printf("Numbers from 10 to 1:\n");
    for (int i = 10; i >= 1; i--)
    {
        printf("%d ", i);
    }
    printf("\n");
    pthread_mutex_unlock(&lock); // Unlock
    return NULL;
}

int main()
{
    pthread_t tid;

    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Create thread
    pthread_create(&tid, NULL, printDescending, NULL);

    // Wait for thread to finish
    pthread_join(tid, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&lock);

    return 0;
}


//Implement a C program to create a thread that generates random numbers and synchronizes access to a shared buffer?


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

pthread_mutex_t lock;
int buffer[5];

void *generateRandom(void *arg)
{
    pthread_mutex_lock(&lock);

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        buffer[i] = rand() % 100;
        printf("Generated: %d\n", buffer[i]);
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t tid;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&tid, NULL, generateRandom, NULL);
    pthread_join(tid, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}


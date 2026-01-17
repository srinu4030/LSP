//Write a C program to implement the producer-consumer problem using pthreads. Create
//two threads - one for producing items and another for consuming items from a shared buffer


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 5

int buffer[SIZE];
int count = 0;
pthread_mutex_t lock;
sem_t empty, full;

void *producer(void *arg)
{
    for (int i = 1; i <= 10; i++)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&lock);

        buffer[count++] = i;
        printf("Produced: %d\n", i);

        pthread_mutex_unlock(&lock);
        sem_post(&full);
    }
    return NULL;
}

void *consumer(void *arg)
{
    for (int i = 1; i <= 10; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&lock);

        int item = buffer[--count];
        printf("Consumed: %d\n", item);

        pthread_mutex_unlock(&lock);
        sem_post(&empty);
    }
    return NULL;
}

int main()
{
    pthread_t prod, cons;
    pthread_mutex_init(&lock, NULL);
    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&lock);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}


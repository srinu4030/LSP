//program to use semaphore instead of mutex locks for thread synchronization?

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int sharedVar = 0;
sem_t sem;

void *increment(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        sem_wait(&sem); // acquire
        sharedVar++;
        sem_post(&sem); // release
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    sem_init(&sem, 0, 1); // binary semaphore

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final value of shared variable = %d\n", sharedVar);

    sem_destroy(&sem);
    return 0;
}



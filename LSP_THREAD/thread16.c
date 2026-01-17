//Develop a C program to create a thread that reads input from the user and synchronizes access to shared resources?


#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
char shared_data[100];

void *readInput(void *arg)
{
    pthread_mutex_lock(&lock);

    printf("Enter a string: ");
    fgets(shared_data, sizeof(shared_data), stdin);

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t tid;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&tid, NULL, readInput, NULL);
    pthread_join(tid, NULL);

    pthread_mutex_lock(&lock);
    printf("Shared Data: %s", shared_data);
    pthread_mutex_unlock(&lock);

    pthread_mutex_destroy(&lock);
    return 0;
}


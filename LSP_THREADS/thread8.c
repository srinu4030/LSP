//Write a C program to create a thread that prints the current date and time?

#include <stdio.h>
#include <pthread.h>
#include <time.h>

void *printDateTime(void *arg)
{
    time_t now;
    struct tm *local;

    time(&now);
    local = localtime(&now);

    printf("Current Date & Time: %s", asctime(local));
    return NULL;
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, printDateTime, NULL);
    pthread_join(tid, NULL);

    return 0;
}


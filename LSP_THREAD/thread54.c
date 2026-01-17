//Modify the previous program to pass arguments to the threads and print those arguments
//along with the thread ID?

#include <stdio.h>
#include <pthread.h>

void *printMessage(void *arg)
{
    char *msg = (char *)arg;
    printf("Thread ID: %lu - Message: %s\n", (unsigned long)pthread_self(), msg);
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    char *msg1 = "Hello from Thread 1!";
    char *msg2 = "Hello from Thread 2!";

    pthread_create(&t1, NULL, printMessage, msg1);
    pthread_create(&t2, NULL, printMessage, msg2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}


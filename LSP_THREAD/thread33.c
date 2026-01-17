//Implement a C program to create a thread that generates a random string?


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

void *generateRandomString(void *arg)
{
    char str[10];
    int length = 8;

    srand(time(NULL));

    for (int i = 0; i < length; i++)
        str[i] = 'a' + rand() % 26;

    str[length] = '\0';

    printf("Random String: %s\n", str);
    return NULL;
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, generateRandomString, NULL);
    pthread_join(tid, NULL);

    return 0;
}


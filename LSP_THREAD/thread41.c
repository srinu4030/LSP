//Write a C program to create a thread that generates a random password?

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

void *generatePassword(void *arg)
{
    int length = 8;
    char password[9];
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    srand(time(NULL));

    for (int i = 0; i < length; i++)
        password[i] = charset[rand() % (sizeof(charset) - 1)];

    password[length] = '\0';
    printf("Random Password: %s\n", password);
    return NULL;
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, generatePassword, NULL);
    pthread_join(tid, NULL);

    return 0;
}


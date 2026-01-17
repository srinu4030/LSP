//Develop a C program to create a thread that calculates the length of a given string?

#include <stdio.h>
#include <pthread.h>
#include <string.h>

char str[100];

void *stringLength(void *arg)
{
    int len = strlen(str);
    printf("Length of the string '%s' = %d\n", str, len);
    return NULL;
}

int main()
{
    pthread_t tid;

    printf("Enter a string: ");
    scanf("%s", str);

    pthread_create(&tid, NULL, stringLength, NULL);
    pthread_join(tid, NULL);

    return 0;
}


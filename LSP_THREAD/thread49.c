//Develop a C program to create a thread that reverses a given string?

#include <stdio.h>
#include <pthread.h>
#include <string.h>

char str[100];

void *reverseString(void *arg)
{
    int n = strlen(str);
    printf("Reversed string: ");
    for (int i = n - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
    return NULL;
}

int main()
{
    pthread_t tid;

    printf("Enter a string: ");
    scanf("%s", str);

    pthread_create(&tid, NULL, reverseString, NULL);
    pthread_join(tid, NULL);

    return 0;
}


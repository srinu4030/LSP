//Implement a C program to create a thread that reads input from the user?

#include <stdio.h>
#include <pthread.h>

char input[100];

void *readInput(void *arg)
{
    printf("Enter input: ");
    scanf("%s", input);
    printf("You entered: %s\n", input);
    return NULL;
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, readInput, NULL);
    pthread_join(tid, NULL);

    return 0;
}


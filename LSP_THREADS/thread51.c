//Write a C program to create a thread that performs addition of two matrices?

#include <stdio.h>
#include <pthread.h>

int A[2][2], B[2][2], C[2][2];

void *addMatrices(void *arg)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = A[i][j] + B[i][j];

    printf("Sum Matrix:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return NULL;
}

int main()
{
    pthread_t tid;

    printf("Enter elements of Matrix A (2x2):\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B (2x2):\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &B[i][j]);

    pthread_create(&tid, NULL, addMatrices, NULL);
    pthread_join(tid, NULL);

    return 0;
}


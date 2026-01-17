//Develop a C program to create a thread that calculates the area of a triangle?

#include <stdio.h>
#include <pthread.h>

void *areaTriangle(void *arg)
{
    float *data = (float *)arg;
    float area = 0.5 * data[0] * data[1];
    printf("Area of Triangle = %.2f\n", area);
    return NULL;
}

int main()
{
    pthread_t tid;
    float values[2];

    printf("Enter base and height: ");
    scanf("%f %f", &values[0], &values[1]);

    pthread_create(&tid, NULL, areaTriangle, values);
    pthread_join(tid, NULL);

    return 0;
}


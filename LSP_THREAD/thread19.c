//Write a C program to create a thread that checks if a given year is a leap year using dynamic programming with mutex locks?

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

/* DP cache:
   index 0 -> not leap year
   index 1 -> leap year
   -1 means not computed yet
*/
int leap_cache = -1;
int year;

int isLeapYear(int y)
{
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

void *checkLeapYear(void *arg)
{
    pthread_mutex_lock(&lock);

    if (leap_cache == -1)   // DP: compute only once
    {
        leap_cache = isLeapYear(year);
    }

    if (leap_cache)
        printf("%d is a Leap Year\n", year);
    else
        printf("%d is NOT a Leap Year\n", year);

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t tid;

    printf("Enter a year: ");
    scanf("%d", &year);

    pthread_mutex_init(&lock, NULL);

    pthread_create(&tid, NULL, checkLeapYear, NULL);
    pthread_join(tid, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}


//Implement a C program to create a thread that checks if a given string is a palindrome?

#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *checkPalindrome(void *arg)
{
    char *str = (char *)arg;
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right)
    {
        if (str[left] != str[right])
        {
            printf("'%s' is NOT a palindrome\n", str);
            return NULL;
        }
        left++;
        right--;
    }

    printf("'%s' is a palindrome\n", str);
    return NULL;
}

int main()
{
    pthread_t tid;
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);   // reads a single word

    pthread_create(&tid, NULL, checkPalindrome, str);
    pthread_join(tid, NULL);

    return 0;
}


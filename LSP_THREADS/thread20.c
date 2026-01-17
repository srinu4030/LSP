//Write a C program to create a thread that checks if a given string is a palindrome using
//dynamic programming with mutex locks?

#include <stdio.h>
#include <pthread.h>
#include <string.h>

pthread_mutex_t lock;
char str[100];
int dp[100][100];

void *checkPalindrome(void *arg)
{
    pthread_mutex_lock(&lock);

    int n = strlen(str);

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            if (str[i] == str[j])
            {
                if (len == 2)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i + 1][j - 1];
            }
            else
                dp[i][j] = 0;
        }
    }

    if (dp[0][n - 1])
        printf("'%s' is a Palindrome\n", str);
    else
        printf("'%s' is NOT a Palindrome\n", str);

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t tid;
    printf("Enter string: ");
    scanf("%s", str);

    pthread_mutex_init(&lock, NULL);
    pthread_create(&tid, NULL, checkPalindrome, NULL);
    pthread_join(tid, NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}


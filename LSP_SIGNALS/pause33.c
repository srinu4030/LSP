//pause() system call

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void handleSignal(int sig)
{
    printf("\nReceived signal %d! Exiting pause...\n", sig);
}

int main()
{
    // Register signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, handleSignal);

    printf("Process is now paused. Press Ctrl+C to send SIGINT.\n");

    // Suspend process until a signal is caught
    pause();

    printf("Process resumed after receiving signal.\n");

    return 0;
}


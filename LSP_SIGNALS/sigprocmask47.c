//Write a program to demonstrate how to block signals using sigprocmask().

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handleSigint(int sig) {
    printf("\nCaught SIGINT (Ctrl+C)!\n");
}

int main() {
    sigset_t newSet, oldSet;

    // Register a handler for SIGINT
    signal(SIGINT, handleSigint);

    // Initialize the signal set and add SIGINT
    sigemptyset(&newSet);
    sigaddset(&newSet, SIGINT);

    // Block SIGINT and save current signal mask
    if (sigprocmask(SIG_BLOCK, &newSet, &oldSet) < 0) {
        perror("sigprocmask");
        return 1;
    }

    printf("SIGINT is now blocked. Try pressing Ctrl+C. It won't be delivered.\n");
    printf("Sleeping for 10 seconds...\n");
    sleep(10);

    // Unblock SIGINT (restore previous mask)
    if (sigprocmask(SIG_SETMASK, &oldSet, NULL) < 0) {
        perror("sigprocmask");
        return 1;
    }

    printf("SIGINT is unblocked now. Press Ctrl+C again to catch it.\n");

    // Sleep again to test signal handling
    sleep(10);

    printf("Program exiting.\n");
    return 0;
}


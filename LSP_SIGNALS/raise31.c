//Why we use raise system call explain it programmatically


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGUSR1
void handleSignal(int sig) {
    printf("Received signal %d! Handler executed.\n", sig);
}

int main() {
    // Register signal handler for SIGUSR1
    signal(SIGUSR1, handleSignal);

    printf("Program started. Raising SIGUSR1 signal...\n");

    // Send SIGUSR1 to the current process
    raise(SIGUSR1);

    printf("Program continues after handling the signal.\n");

    return 0;
}


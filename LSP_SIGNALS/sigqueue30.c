//Write a program to handle a real-time signal using sigqueue().

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler
void handler(int sig, siginfo_t *info, void *ucontext) {
    printf("Received signal %d\n", sig);
    printf("Sender PID: %d\n", info->si_pid);
    printf("Sent value: %d\n", info->si_value.sival_int);
}

int main() {
    struct sigaction sa;

    // Set up the handler for real-time signal SIGRTMIN
    sa.sa_sigaction = handler;      // use sa_sigaction for extended info
    sa.sa_flags = SA_SIGINFO;       // get siginfo_t
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGRTMIN, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    pid_t pid = getpid();
    union sigval value;
    value.sival_int = 123; // arbitrary value to send

    printf("Sending real-time signal SIGRTMIN to PID %d with value %d\n", pid, value.sival_int);

    // Send signal to self
    if (sigqueue(pid, SIGRTMIN, value) == -1) {
        perror("sigqueue");
        exit(1);
    }

    // Wait for signal to be handled
    sleep(1);

    return 0;
}


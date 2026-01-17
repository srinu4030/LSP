//Implement a program to handle SIGUSR1_SIGUSR2 signal(user-defined signal)


#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void user_signal_handler(int signum);

int main(){
	struct sigaction sa;
	sa.sa_handler=user_signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("Process ID : %d\n", getpid());
	printf("Waiting for SIGUSR1 or SIGUSR2...\n");

	while(1)
		pause();
	return 0;
}
void user_signal_handler(int signum){
	if(signum==SIGUSR1)
		printf("Caught SIGUSR1 (User-defined signal 1)\n");
	else if (signum==SIGUSR2)
		printf("Caught SIGUSR2 (User-defined signal 2)\n");
}

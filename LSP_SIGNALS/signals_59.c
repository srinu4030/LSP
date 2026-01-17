//Write a program to demostrate the usage of sigaction() for handling SIGUSR1 and SIGUSR2 signals in a system programming 

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void signal_handler(int signum, siginfo_t *info, void*context);

int main(){
	struct sigaction sa;
	//Initialize sigaction structure
	sa.sa_sigaction=signal_handler;
	sa.sa_flags=SA_SIGINFO;
	sigemptyset(&sa.sa_mask);

	//register handlers
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("Process PID : %d\n", getpid());
	printf("Send signals using : \n");
	printf(" kill -USR1 %d\n", getpid());
	printf(" kill -USR2 %d\n", getpid());

	while(1)
		pause();
	return 0;
}
void signal_handler(int signum, siginfo_t *info, void *context){
	if(signum==SIGUSR1)
		printf("Received SIGUSR1 from PID %d\n", info->si_pid);
	else if(signum==SIGUSR2)
		printf("Received SIGUSR2 from PID %d\n", info->si_pid);
}

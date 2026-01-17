//Implement a C program to handle the SIGALRM() using sigaction.

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void alarm_handler(int sig);

int main(){
	struct sigaction sa;
	sa.sa_handler=alarm_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;

	sigaction(SIGALRM, &sa, NULL);
	printf("Setting alaram for 5 seconds...\n");
	alarm(5);

	pause();
	printf("Program exiting after handling SIGALRM\n");
	return 0;
}
void alarm_handler(int sig){
	printf("SIGALRM received! Signal number : %d\n", sig);
}

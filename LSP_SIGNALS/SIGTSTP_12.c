//Write a program to handle SIGTSTP terminal stop

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sigtstp_handler(int signum);
int main(){
	//register SIGTSTP handler
	signal(SIGTSTP, sigtstp_handler);
	printf("Process ID : %d\n", getpid());
	printf("Program running ...Press ctrl+z to send SIGSTP\n");

	while(1){
		sleep(1);
	}
	return 0;
}
//Signal handler function
void sigtstp_handler(int signum){
	printf("\nSIGTSTP %d received.\n", signum);
	printf("Terminal stop signal handled. Process continues....\n");
}


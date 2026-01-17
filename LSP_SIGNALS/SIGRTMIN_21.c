//Write a program to handle SIGRTMIN signal(Minimum real-time signal)
//SIGRTMIN is used for reliable, queued, and priority-based inter-process communication in real time applications.
#include<stdio.h>
#include<signal.h>
#include<unistd.h>


void sigrtmin_handler(int signum);
int main(){
	if(signal(SIGRTMIN, sigrtmin_handler)==SIG_ERR){
		perror("signal");
		return 1;
	}
	printf("Process ID : %d\n", getpid());
	printf("Waiting for SIGRTMIN signal...\n");

	while(1){
		pause();
	}
	return 0;
}
void sigrtmin_handler(int signum){
	printf("Received SIGRTMIN signal : %d\n", signum);
}


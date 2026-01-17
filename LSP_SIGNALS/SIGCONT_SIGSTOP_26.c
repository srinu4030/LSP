//SISCONT_SIGSTOP signal

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sigcont_handler(int signum);

int main(){
	if(signal(SIGCONT, sigcont_handler)==SIG_ERR){
		perror("signal");
		return 1;
	}
	printf("Process ID : %d\n", getpid());
	printf("Process is running...\n");
	printf("Send SIGSTOP to stop and SIGCONT to resume\n");

	while(1){
		printf("Working...\n");
		sleep(2);
	}
	return 0;
}
void sigcont_handler(int signum){
	printf("\nSIGCONT received %d\n", signum);
	printf("process resumed after SIGSTOP\n");
}

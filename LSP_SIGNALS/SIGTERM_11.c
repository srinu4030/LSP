//Write a program to handle the SIGTERM signal(termination request)


#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sigterm_handler(int signum);
int main(){
	//register SIGTER handler
	signal(SIGTERM, sigterm_handler);
	printf("Process ID : %d\n", getpid());
	printf("Program running... Send SIGTERM using kill command\n");
	while(1){
		sleep(1);
	}
	return 0;
}
void sigterm_handler(int signum){
	printf("\nSIGTERM %d received.\n", signum);
	printf("Terminating process using kill command\n");
	exit(0);
}


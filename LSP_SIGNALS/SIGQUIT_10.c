//Implement a C program to handle theSIGQUIT signal

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void sigquit_handle(int signum);
int main(){
	//register SIGQUIT handler
	signal(SIGQUIT, sigquit_handle);

	printf("Program running...Press ctrl+\\ to send SIGQUIT\n");

	//infinite loop to keep program running
	while(1){
		sleep(1);
	}
	return 0;
}
void sigquit_handle(int signum){
	printf("\nSIGQUIT %d received.\n", signum);
	printf("Handling SIGQUIT... Program will not terminate.\n");
}
	

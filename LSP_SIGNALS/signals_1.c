//Write a C program to catch and handle the SIGINT signal?

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sigint_handler(int signum);

int main(){
	//register signal handler for SIGINT
	signal(SIGINT, sigint_handler);
	printf("Program is running... Press Ctrl+C to test SIGINT handling.\n");
	
	while(1){
		sleep(1);
		printf("Running...\n");
	}
	return 0;
}
void sigint_handler(int signum){
	printf("\nSIGINT caught! Signal number : %d\n", signum);
	printf("Ctrl+C pressed, but program will not terminate.\n");
}

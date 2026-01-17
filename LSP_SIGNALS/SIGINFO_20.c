//Write a program to handle SIGINFO signal (status request from keyboard)
//Linux does not support SIGINFO
//So there is no direct program with SIFINFO on Linux
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void siginfo_handler(int signum);
int main(){
	//signal(SIGINFO, siginfo_handler);
	signal(SIGUSR1, siginfo_handler);
	printf("Program running...\n");
	printf("Press ctrl+T to generate SIGINFO\n");

	while(1)
		pause();
	return 0;
}
void siginfo_handler(int signum){
	printf("\nCaught SIGINFO : Status request received from keyboard\n");
}

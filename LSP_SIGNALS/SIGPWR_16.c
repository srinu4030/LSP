//Write a C program to handle SIGPWR signal (Power failure/ restart)

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sigpwr_handler(int signum);
int main(){
	signal(SIGPWR, sigpwr_handler);
	printf("Waiting dor SIGPWR..\n");
	while(1){
		sleep(1);
	}
	return 0;
}
void sigpwr_handler(int signum){
	printf("Caught SIGPWR : Power failure detected!\n");
	exit(1);
}


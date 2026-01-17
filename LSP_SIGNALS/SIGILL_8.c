//Create a program to handle SIGILL signal(illegal instruction).

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sigill_handler(int signum);

int main(){
	//register signal handler
	signal(SIGILL, sigill_handler);
	printf("SIGILL handler registered.\n");

	//intentionally raise SIGILL
	raise(4);
	raise(SIGILL);

	return 0;
}
void sigill_handler(int signum){
	printf("Caught signal %d (SIGILL : Illegal Instruction)\n", signum);
	printf("Illegal instruction handled successfully.\n");
	exit(1);
}

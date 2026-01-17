//Write a program to handle SIGABRT signal (Abort)

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sigabrt_handler(int signum);
int main(){
	signal(SIGABRT, sigabrt_handler);

	printf("SIGABRT handler registered.\n");
	//Intentionally generate SIGABRT
	abort();
	return 0;
}
void sigabrt_handler(int signum){
	printf("Caught signal %d (SIGABRT : Abort)\n", signum);
	printf("Abort signal handled successfully.\n");
	exit(1);
}



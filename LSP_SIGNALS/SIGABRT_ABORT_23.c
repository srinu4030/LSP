//SIGABRT_ABORT(abort signal)


#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void sigabrt_handler(int signum);

int main(){
	signal(SIGABRT, sigabrt_handler);

	printf("Program started...\n");
	printf("Raising SIGABRT now\n");

	abort();  //generates SIGABRT
	printf("The line will never executed\n");
	return 0;
}
void sigabrt_handler(int signum){
	printf("Caught SIGABRT signal %d \n", signum);
	printf("Performing cleanup before termination....\n");

	signal(SIGABRT, SIG_DFL);//Restore default signal				//
	abort();   //terminate program
}


//Implement the program to handle the SIGSEGV signal (segmentation fault)

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void segv_handler(int signum);
int main(){
	signal(SIGSEGV, segv_handler);
	printf("SIGSEGV handler registered.\n");

	int *ptr=NULL; //interntionally cause segmentation fault
	*ptr=10;  //Invalid memory
	return 0;
}
void segv_handler(int signum){
	printf("Caught signal %d (SIGSEGV : Segmentation fault)\n", signum);
	printf("Segmentation afult handled successfully.\n");
	exit(1);
}



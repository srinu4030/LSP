//Program to handle SIGSEGV_SIGBUS signal(SEgmentation fault or bus error)

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void fault_handler(int signum, siginfo_t *info, void*context);
int main(){
	struct sigaction sa;
	sa.sa_sigaction=fault_handler;
	sa.sa_flags=SA_SIGINFO;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGSEGV, &sa, NULL);
	sigaction(SIGBUS, &sa, NULL);

	printf("Program started...\n");

	int *ptr=NULL;
	*ptr=10;
	printf("The line will never execute\n");
	return 0;
}
void fault_handler(int signum, siginfo_t *info, void *context){
	if(signum==SIGSEGV){
		printf("Caught SIGSEGV (Segmentation fault)\n");
	}
	if(signum==SIGBUS){
		printf("Caught SIGBUS (Bus error)\n");
	}
	printf("Fault address : %p\n", info->si_addr);

	printf("Program terminating safely...\n");
	exit(1);
}


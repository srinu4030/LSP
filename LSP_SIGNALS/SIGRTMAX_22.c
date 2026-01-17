//SIGRTMAX(64) signal (maximum real time signal)
//SIGRTMIN(34), SIGRTMAX(64)


#include<stdio.h>
#include<signal.h>

void sigrtmax_handler(int signum, siginfo_t *info, void *ucontext);

int main(){
	struct sigaction sa;
	sa.sa_flags=SA_SIGINFO;
	sa.sa_sigaction=sigrtmax_handler;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGRTMAX, &sa, NULL);

	printf("Waiting for SIGRTMAX..\n");
	while(1);
}
void sigrtmax_handler(int signum, siginfo_t *info, void*ucontext){
	printf("REceived signal : %d\n", signum);
	printf("Data received : %d\n", info->si_value.sival_int);
}



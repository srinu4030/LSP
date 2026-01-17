//Write a program to demostrate how to block and unblock signals using sigprocmask() ins system programming context

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sigusr1_handler(int signum);

int main(){
	sigset_t block_set, old_set;
	
	//Install signal handler
	signal(SIGUSR1, sigusr1_handler);
	
	//Initialize signal set
	sigemptyset(&block_set);
	sigaddset(&block_set, SIGUSR1);

	printf("Process PID : %d\n", getpid());

	//block SIGUSR1
	sigprocmask(SIG_BLOCK, &block_set, &old_set);
	printf("SIGUSR1 blocked\n");
	printf("Send SIGUSR1 now : kill -USR1 %d\n", getpid());

	sleep(10);
	printf("Unblocking SIGUSR1...\n");
	//Unblock SIGUSR1
	sigprocmask(SIG_SETMASK, &old_set, NULL);

	sleep(2);
	return 0;
}
void sigusr1_handler(int signum){
	printf("SIGUSR1 received and handled\n");
}


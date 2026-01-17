//SIGPWR_SIGSYS signal (power failure restart or bad system call)


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sigpwr_handler(int signum);
void sigsys_handler(int signum);

int main(){
	//register signal handlers
	signal(SIGPWR, sigpwr_handler);
	signal(SIGSYS, sigsys_handler);

	printf("Process ID : %d\n", getpid());
	printf("Send SIGPWR using  : kill -SIGPWR %d\n", getpid());
	printf("Send SIGSYS using : kill -SIGSYS %d\n", getpid());

	while(1){
		pause();
	}
	return 0;
}
void sigpwr_handler(int signum){
	printf("SIGPWR caught : Powerfailure or restart detected\n");
}
void sigsys_handler(int signum){
	printf("SIGSYS caught : Bad system call attempted\n");
	exit(1);
}


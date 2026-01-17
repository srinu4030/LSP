//Implement a C program to send a custom signal to another process

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void usr1_handler(int signum);
int main(){
	//register handler for SIGUSR1 (%d)
	signal(SIGUSR1, usr1_handler);

	printf("Receiver process started\n");
	printf("My PID is : %d\n", getpid());

	while(1){
		pause();
	}
	return 0;
}
void usr1_handler(int signum){
	printf("Received custom signal SIGUSR1 (%d)\n", signum);
}

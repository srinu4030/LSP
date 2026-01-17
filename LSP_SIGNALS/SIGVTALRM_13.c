//Write a program to handle the SIGVTALRM signal(virtual timeexpired)

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>

void sigvtalrm_handler(int signum);
int main(){
	struct itimerval timer;
	//register signal handler
	signal(SIGVTALRM, sigvtalrm_handler);
	
	//set virtual timer
	timer.it_value.tv_sec=2; //first expiration after 2 sec of CPU time
	timer.it_value.tv_usec=0;
	timer.it_interval.tv_sec=2;//periodic interval
	timer.it_interval.tv_usec=0;

	setitimer(ITIMER_VIRTUAL, &timer, NULL);
	
	//busy loop to continue CPU time
	while(1){
		//cpu intensive work

	}
	return 0;
}
void sigvtalrm_handler(int signum){
	printf("\nSIGVTALRM %d received : Virtual time expired\n", signum);
}
	

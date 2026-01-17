//fork() to create a child
//SIGUSR1 handler in parent
//SIGUSR1 handler in child


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
pid_t child_pid;

void child_handler(int signum);
void parent_handler(int signum);

int main(){
	child_pid=fork();
	if(child_pid<0){
		perror("fork failed");
		exit(1);
	}
	if(child_pid==0){
		//cjild process
		signal(SIGUSR1, child_handler);
		printf("Child (PID %d ) waiting for SIGUSR1....\n", getpid());
		while(1){
			pause();
		}
	}
	else{
		//parent process
		signal(SIGUSR1, parent_handler);
		printf("Parent pid = %d, Child pid = %d\n", getpid(), child_pid);
		printf("Send SIGUSR1 to parent using : kill -USR1 %d\n", getpid());

		while(1){
			pause();
		}
	}
	return 0;
}
void child_handler(int signum){
	printf("Child PID = %d : Received SIGUSR1 from parent\n", getpid());
}
void parent_handler(int signum){
	printf("Parent PID = %d : Received SIGUSR1\n", getpid());
	printf("Parent : Sending SIGUSR1 to child (PID %d)\n", child_pid);

	kill(child_pid, SIGUSR1);
}




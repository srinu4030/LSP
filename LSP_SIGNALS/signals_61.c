//SIGBUS_SIGCHLD signal(bus error or child process terminated)

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

void sigbus_handler(int signum);
void sigchld_handler(int signum);

int main(){
	pid_t pid;
	//register signal handler
	signal(SIGBUS, sigbus_handler);
	signal(SIGCHLD, sigchld_handler);

	pid=fork();

	if(pid<0){
		perror("fork");
		exit(1);
	}
	if(pid==0){
		//child process
		printf("Child process running , PID = %d\n", getpid());
		sleep(2);
		printf("Child exiting\n");
		exit(0);
	}
	else{
		//parent process
		printf("Parent PID = %d\n", getpid());
		printf("Send SIGBUS using : kill -SIGBUS %d\n", getpid());

		while(1)
			pause();
	}
	return 0;
}
void sigbus_handler(int signum){
	printf("SIGBUS caught : Bus error occured\n");
	exit(1);
}
void sigchld_handler(int signum){
	int status;
	pid_t pid;
	pid=wait(&status);
	printf("SIGCHLD caught : Child process %d terminated\n", pid);
}


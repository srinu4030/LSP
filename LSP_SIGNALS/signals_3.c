//Write a C program to ignore  SIGCHLD signal temporarily

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid;
	printf("Parent process started (PID = %d)\n", getpid());
       //Temporarily ignore SIGCHLD

	signal(SIGCHLD, SIG_IGN);
	printf("SIGCHLD is temporarily ignored\n");
	
	pid=fork();
	if(pid==0){
		printf("Child process running (PID = %d)\n", getpid());
		sleep(2);
		printf("child exiting\n");
		return 0;
	}
	else{
		sleep(5);
		signal(SIGCHLD, SIG_DFL);
		printf("SIGCHLD restored to default handling.\n");

		wait(NULL);
	}
	return 0;
}


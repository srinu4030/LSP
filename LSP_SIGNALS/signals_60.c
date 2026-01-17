//SIGCHLD_SIGCONT(child process terminated or continue executing)

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

void sigchld_handler(int signum);
void sigcont_handler(int signum);

int main(){
	pid_t pid;
	signal(SIGCHLD, sigchld_handler);
	signal(SIGCONT, sigcont_handler);

	pid=fork();

	if(pid<0){
		perror("fork");
		exit(1);
	}
	if(pid==0){
		//child process
		printf("Child PID %d running\n", getpid());
		sleep(2);
		printf("Child stopped (SIGSTOP)\n");
		raise(SIGSTOP);  //child stops itself

		printf("Child resumed (SIGCONT)\n");
		sleep(2);
		printf("Child exiting\n");
		exit(0);
	}
	else{
		//parent process
		printf("Parent PID %d Child PID %d\n", getpid(), pid);

		while(1)
			pause();
	}
	return 0;
}
void sigchld_handler(int signum){
	int status;
	pid_t pid;

	pid=waitpid(-1, &status, WNOHANG|WUNTRACED|WCONTINUED);
	
	if(pid<0){
		if(WIFSTOPPED(status)){
			printf("SIGCHLD : Child %d stopped\n", pid);
			kill(pid, SIGCONT);  //resume child
		}
		else if(WIFCONTINUED(status)){
			printf("SIGCHLD : Child %d continued\n", pid);
		}
		else if (WIFEXITED(status)){
			printf("SIGCHLD : Child %d exited\n", pid);
			exit(0);
		}
	}
}
void sigcont_handler(int signum){
	printf("SIGCONT received : process resumed\n");
}




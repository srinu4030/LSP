//Write a program to handle the SIGPIPE_SIGQUIT signal(write on a ppipe with no on e to read it or quit signal)

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

void sigpipe_handler(int signum);
void sigquit_handler(int signum);

int main(){
	int fd[2];
	pid_t pid;

	//register signal handler
	signal(SIGPIPE, sigpipe_handler);
	signal(SIGQUIT, sigquit_handler);

	if(pipe(fd)==-1){
		perror("pipe");
		exit(1);
	}
	pid=fork();
	if(pid<0){
		perror("fork");
		exit(1);
	}
	if(pid==0){
		//child process : closes read end and exists
		close(fd[0]);
		close(fd[1]);
		exit(0);
	}
	else{
		close(fd[0]);  // close read end
		sleep(2);      //ensure child exists
		printf("Writing to pipe with no reader...\n");
		//This write causes SIGPIPE
		write(fd[1], "srinu", 5);

		//wait for SIGQUIT
		printf("Press ctrl+\\ to generate SIGQUIT\n");
		while(1){
			pause();
		}
		return 0;
	}
}
void sigpipe_handler(int signum){
       printf("SIGPIPE caught : No reader on the pipe\n");
}
void sigquit_handler(int signum){
	printf("SIGQUIT caught : Quit signal received\n");
	exit(0);
}

























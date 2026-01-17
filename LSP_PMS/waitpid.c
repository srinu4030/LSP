//Another variant of wait() system call is waitpid()

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
	int status;
	pid_t pid;
	pid=fork();
	if(pid==0){
		for(int i=0; i<10; i++){
			printf("Child process.\n");
			sleep(1);
		}
		exit(2);
	}
	else{
		for(int i=0; i<5; i++){
			printf("Parent process.\n");
			sleep(1);
		}
	}
	printf("Waiting for child process termination.\n");
	waitpid(pid, &status, 0);
	printf("The Child process is terminated with exit code : %d\n", WEXITSTATUS(status));
}



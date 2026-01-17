//Write a C program to create a process using fork() and pass arguments to the child process

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
	int status;
	pid_t pid;
	pid=fork();
	if(pid<0){
		perror("fork failed.\n");
		return 1;
	}
	else if (pid==0){
		printf("Child process.\n");
		printf("Child PID : %d\n", getpid());
		printf("Parent PID : %d\n", getppid());

		printf("The argument received by the child : \n");
		for(int i=0; i<argc; i++){
			printf("argv[%d]=%s\n",i, argv[i]);
		}
		exit(6);
	}
	else{
		printf("Parent process: \n");
		printf("Parent PID =%d\n", getpid());
		wait(&status);
		printf("The child exited with exit codes of : %d\n", WEXITSTATUS(status));
		printf("Child exited.\n");
	}
	return 0;
}


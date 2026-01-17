//Write a C program to create a child process using fork() and print its PID

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	pid_t pid;
	pid=fork();
	if(pid<0){
		printf("Fork failed");
		return 1;
	}
	else if(pid==0){
		printf("Child Process\n");
		printf("Child PID : %d\n", getpid()); // returns the PID of the current process
		printf("Parent PID : %d\n", getppid());//returns the PID of the parent process
	}
	else{
		printf("Parent process\n");
		printf("Parent PID : %d\n", getpid());
		printf("Child PID : %d\n", pid);
	}
	return 0;
}


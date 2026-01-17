//Write a C program tto demonstrate the use of waitpid() function for process synchronization


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
	int status;
	pid_t pid;
	pid=fork();
	if(pid==0){
		//child process
		printf("Child process running (PID = %d)\n", getpid());
		sleep(3);
		printf("Child process exiting\n");
		exit(10);//exit with status 10
	}
	else{
		//parent process
		printf("Parent waiting for child (PID = %d)\n", pid);
		waitpid(pid, &status, 0);
		if(WIFEXITED(status)){
			printf("Child exited normally with status= %d\n", WEXITSTATUS(status));
		}
		printf("Parent process continues execution\n");
	}
	return 0;
}




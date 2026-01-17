//Write a C program to create multiple child process using fork() and display their PIDs

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	int i;
	int n=3;
	for(i=0; i<n; i++){
		pid_t pid=fork();
		if(pid<0){
			perror("Fork failed");
			return 1;
		}
		else if(pid==0){
			printf("Child %d: PID = %d, Parent PID = %d\n", i+1, getpid(), getppid());
		        return 0;
		}
	}
	printf("Parent Process : PID = %d\n", getpid());
	return 0;
}

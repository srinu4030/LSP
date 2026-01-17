//How do you make sure that parent process blocks or waits until your child process termination?
//we have to use wait() system call

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
	int pid;
	int stat;
	pid=fork();
	if(pid==0){
		for(int i=0; i<10; i++){
			printf("This is child process.\n");
			sleep(1);
		}
		exit(5);
	}
	else{
		for(int i=0; i<5; i++){
			printf("This is parent process.\n");
			sleep(1);
		} 
	}
	printf("Waiting for child process termination.\n");
	wait(&stat);
	printf("Child process terminated with exit code : %d\n", WEXITSTATUS(stat));
}



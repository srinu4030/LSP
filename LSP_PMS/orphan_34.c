//Orphan Process

#include<stdio.h>
#include<unistd.h>
int main(){
	pid_t pid;
	pid=fork();
	if(pid<0){
		perror("fork failed.\n");
		return 1;
	}
	if(pid==0){
		printf("Child PID : %d\n", getpid());
		sleep(5);
		for(int i=0; i<10; i++){
			printf("Child process.\n");
			//sleep(1);
	                printf("NEW PARENT PID : %d\n", getppid());
			sleep(1);
		}
	}
	else{
		printf("Parent PID : %d\n", getpid());
		for(int i=0; i<5; i++){
			printf("Parent process\n");
			sleep(1);
		}
		printf("Parent exiting now...\n");
		
	}
	return 0;
}

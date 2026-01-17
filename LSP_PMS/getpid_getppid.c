//getpid() and getppid()

#include<stdio.h>
#include<unistd.h>
int main(){
	pid_t pid;
	pid=fork();
	if(pid<0){
		printf("Fork failed\n");
		return 1;
	}
	else if(pid==0){
		printf("The Child Process\n");
		printf("Child PID : %d\n", getpid());
		printf("Parent PID : %d\n", getppid());
	}
	else{
		printf("The Parent Process\n");
		printf("The parent PID : %d\n", getpid());
		printf("The child PID : %d\n", pid);
	}
	return 0;
}

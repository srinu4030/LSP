//fork()+execvp()

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
	int status;
	pid_t pid;
	pid=fork();

	if(pid<0){
		perror("Fork failed");
		return 1;
	}
	else if(pid==0){
		printf("Child process\n");
		//exit(5);
		char *args[]={"ps", "-ef", NULL};
		execvp("ps", args);
		exit(6);
		printf("hello\n");
	}
	else{
		printf("Parent process\n");
		wait(&status);
		printf("The exit code child process is : %d\n", WEXITSTATUS(status));
	}
	return 0;
}
		

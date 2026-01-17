//Write a C program to illustrate the use of the execvp() function
// int execvp(const char *file, char *const argv[]);
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	pid_t pid;
	pid=fork();
	if(pid==0){
		char *args[]={"ls", "-l", NULL};
		execv("/bin/ls", args);
		perror("execv failed");
	}
	else if (pid>0){
		wait(NULL);
		printf("Parent : Child finished execution\n");
	}
	else{
		perror("fork failed");
	}
	return 0;
	
}

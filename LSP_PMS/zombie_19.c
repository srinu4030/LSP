//Write a C program to create a zombie process and how to avoid it 

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
/*int main(){
	pid_t pid;
	pid=fork(); //creates a child process
	if(pid==0){
		//child process
		printf("Child process exiting..\n");
		return 0;
	}
	else{
		//parent process
		printf("Parent process sleeping..\n");
		sleep(20);//parent sleeps and does not call wait()
		printf("Parent process exiting..\n");
	}
	return 0;
}*/

	
int main(){
	pid_t pid;
	pid=fork();
	if(pid==0){
		printf("Child exiting ..\n");
		exit(0);
	}
	else{
		//wait(NULL);
		//waitpid(pid, NULL, 0);
		signal(SIGCHLD, SIG_IGN);
		printf("Child cleaned, no zombie\n");
	}
	return 0;
}



















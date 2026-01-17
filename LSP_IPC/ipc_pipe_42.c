//Create a program where two processes communicate synchronously using pipe. Ensure that one process waits for the other to finish before proceeding.

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main(){
	int fd[2];
	pid_t pid;
	char write_msg[]="Message from parent";
	char read_msg[30];

	if(pipe(fd)==-1){
		perror("pipe failed");
		return 1;
	}
	pid=fork();
	if(pid<0){
		perror("fork failed");
		return 1;
	}
	if(pid==0){
		close(fd[1]);
		read(fd[0], read_msg, sizeof(read_msg));
		printf("Child received : %s\n", read_msg);

		close(fd[0]);
		_exit(0);
	}
	else{
		close(fd[0]);
		write(fd[1], write_msg, strlen(write_msg)+1);
		close(fd[1]);
		wait(NULL);
		printf("Parent : Child finished execution\n");
	}
	return 0;
}

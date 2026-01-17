//Implement a program that uses pipes for communication between a parent and child process. Show how data can be passed between processes using pipes.

#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){
	int fd[2];   //fd[0]->read end, fd[1]->write end
	pid_t pid;
	char write_msg[]="Hello from parent";
	char read_msg[30];

	if(pipe(fd)==-1){
		perror("Pipe failed");
		return 1;
	}
	pid=fork();

	if(pid<0){
		perror("Fork failed");
		return 1;
	}
	if(pid==0){
		//Child  process
		close(fd[1]);   //close write end
		printf("Child process\n");
		read(fd[0], read_msg, sizeof(read_msg));
		printf("Child received : %s\n", read_msg);
		close(fd[0]);
	}
	else{
		//parent process
		close(fd[0]);   //Close read end
		printf("Parent process\n");
		write(fd[1], write_msg, strlen(write_msg));
		close(fd[1]);
	}
	return 0;
}



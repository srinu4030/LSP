//terminating a parent process before terminating a child process

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	int pid;
	pid=fork();
	if(pid==0){
		for(int i=0; i<10; i++){
			printf("This is child process.\n");
			sleep(1);
		}
	}
	else{
		for(int i=0; i<5; i++){
			printf("This is parent process.\n");
			sleep(1);
		}
	}
}


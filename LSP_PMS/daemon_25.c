//Daemon process->is program that runs in the background without any user interaction or terminal control

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
//gcc daemon_25.c -o dae
//ps -ef | grep dea;

int main(){
	pid_t pid;
	//step1 : fork a child process
	pid=fork();
	if(pid<0){
		perror("fork failed");
		exit(1);
	}
	if(pid>0){
		//parent process
		//this allows child to run in background
		exit(0);
	}
	//step 2: creates a new session
	//child becomes session leader, detaches from terminal
	if(setsid()<0){
		perror("setsid failed");
		exit(1);
	}
	//step 3: optional - change working directory to root
	//This avoids locking the current directory
	chdir("/");
	
	//step 4 : close standard file descriptors
	//Daemon does not use terminal input/ouput
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	
	//step 5 : Daemon main loop
	//Here we simulate work by sleeping every 10 seconds
	while(1){
		sleep(10);
	}
	return 0;
}



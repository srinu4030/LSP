#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	pid_t pid;
	if(argc !=2){
		printf("Usage : %s <PID>\n", argv[0]);
		return 1;
	}
	pid=atoi(argv[1]);
	kill(pid, SIGUSR1);
	printf("SIGUSR1 sent to process %d\n", pid);

	return 0;
}

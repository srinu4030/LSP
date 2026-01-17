//cop on write technique

#include<stdio.h>
#include<unistd.h>
int global=10;
int main(){
	int local=100;
	pid_t pid;
	pid=fork();

	if(pid<0){
		perror("fork failed\n");
		return 0;
	}
	if(pid==0){
		printf("Child process\n");
		printf("Befor modification global = %d, local = %d\n", global, local);
		global=100;
		local=200;
		printf("After modifying global = %d, local = %d\n", global, local);
	}
	else{
		sleep(1);
		printf("Parent process \n");
		printf("After child modification : glocal = %d, local = %d\n", global, local);
		global=100;
		printf("After modifying : global=%d, local=%d", global, local);
	}
	return 0;
}




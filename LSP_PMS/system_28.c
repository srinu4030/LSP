//Write a C program to demostrate the use of the system() function to execute shell commands
//system() is a library function used to execute shell commands from a C program.
//int system(const char *command);
//system() internally uses fork(), exec(), and waitpid() system calls
#include<stdio.h>
#include<stdlib.h>
int main(){
	int ret;
	printf("Executing shell commands using system()..\n");
	ret=system("ls -l");
	printf("ret=%d\n", ret);
	if(ret==-1){
		printf("system() failed\n");
	}
	else{
		printf("Command executed successfully.\n");
	}
	return 0;
}



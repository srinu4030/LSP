//Write a program to handle SIGSYS signal (bad system call)


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sigsys_handler(int signum);
int main(){
	signal(SIGSYS, sigsys_handler);
	syscall(999999);//invalid system call to triggger SIGSYS
	
	return 0;
}
void sigsys_handler(int signum){
	printf("Caught SIGSYS : Bad system call!\n");
	exit(1);
}

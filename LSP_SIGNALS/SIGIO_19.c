//Write a C program to handle SIGIO signal( I/O is possible on a descriptor)


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<fcntl.h>

void sigio_handler(int signum);
int main(){
	int flags;
	signal(SIGIO, sigio_handler);

	//set owner
	fcntl(STDIN_FILENO, F_SETOWN, getpid());
	//Enable async I/O
	flags=fcntl(STDIN_FILENO, F_GETFL);
	fcntl(STDIN_FILENO, F_SETFL, flags|O_ASYNC);

	printf("Waiting for I/O signal (type something)....\n");

	while(1){
		pause();
	}
	return 0;
}
void sigio_handler(int signum){
	char buf[100];
	int n;
	printf("\nCaught SIGIO : I/O is possible!\n");
	n=read(STDIN_FILENO, buf, sizeof(buf)-1);

	if(n>0){
		buf[n]='\0';
		printf("Read data : %s\n", buf);
	}
}


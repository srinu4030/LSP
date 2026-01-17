//Write a program that uses named pipes for commmunication between two processes.

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	char *fifo="/tmp/myfifo";  //char *fifo - a string pointer, "/tmp/myfifo"- the path of the named pipe
	char msg[]="Hello from writer process";

	mkfifo(fifo, 0666);

	int fd=open(fifo, O_WRONLY);
	write(fd, msg, sizeof(msg));

	close(fd);
	return 0;
}

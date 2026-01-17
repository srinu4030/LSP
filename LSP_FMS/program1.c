//Write a program to create a new text file and write hello wolrd to it

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int fd;
	char buf[20]="HELLO WORLD";
	fd=open("file.txt", O_WRONLY|O_CREAT, 0640);
	if(fd==-1){
		printf("Error\n");
		return 1;
	}
	write(fd, buf, strlen(buf));
	printf("Successfully created and written to that file.\n");

	close(fd);
	return 0;
}

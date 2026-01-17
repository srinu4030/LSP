//Write a c program to open an existing text file and display its contents

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(){
	char buf[20];
	int fd;
	fd=open("file.txt", O_RDONLY);
	printf("%d\n", fd);
	if(fd==-1){
		printf("Error.\n");
		return 1;
	}
	int ret=read(fd, buf, 20);
	buf[ret]=0;
	printf("%s\n", buf);
	printf("%d\n", ret);
	close(fd);
	return 0;
}

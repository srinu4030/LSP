//Write a program to copy the contents of one file to another file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(){
	int srcfd, dstfd;
	char buffer[100];
	srcfd=open("file.txt", O_RDONLY);
	if(srcfd==-1){
		perror("srcfd");
		return 1;
	}
	printf("srcfd=%d\n", srcfd);
	dstfd=open("copy.txt", O_WRONLY|O_CREAT, 0777);
	if(dstfd==-1){
		perror("dstfd");
		close(srcfd);
		return 2;
	}
	printf("dstfd=%d\n", dstfd);
	int ret;
	while((ret=read(srcfd, buffer, sizeof(buffer)))>0)
		write(dstfd, buffer, ret);
	close(srcfd);
	close(dstfd);
	printf("File is copied successfully.\n");
	return 0;

}




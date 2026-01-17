//Reader process

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	char *fifo="/tmp/myfifo";
	char buf[100];

	int fd=open(fifo, O_RDONLY);
	read(fd, buf, sizeof(buf));

	printf("Reader received :m %s\n", buf);

	close(fd);
	return 0;
}


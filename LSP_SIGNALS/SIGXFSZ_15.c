//Implement a C program to handle SIGXFSZ signal (file size limit exceeded)

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

void sigxfsz_handler(int signum);
int main(){
	//register the sigxfsz handler
	signal(SIGXFSZ, sigxfsz_handler);

	FILE *fp=fopen("file.txt", "w");
	if(!fp){
		perror("fopen");
		return 1;
	}
	printf("Writing to file until size limit is exceeded...\n");
	/*Loop to intentionally exceed file size limit*/
	char buffer[14];
	memset(buffer, 'A', sizeof(buffer));

	while(1){
		if(fwrite(buffer, 1, sizeof(buffer), fp)< sizeof(buffer)){
			if(errno==EFBIG)//file too big
			{
				printf("Write failed : file sie reached\n");
				break;
			}
		}
		fflush(fp);//force write to disk
	}
	return 0;
}
void sigxfsz_handler(int signum){
	printf("\nSIGXFSZ %d received : File size limit exceeded!\n", signum);
	printf("Terminating gracefully.\n");
	exit(1);
}


//Discuss the role of execv()
//execv() is one of the exec family functions used in linus to replace the current process image with a new program
//The PID remains the same, but code, data, bss, stack, heap are completely replaced be the new program.
//int execv(const char *path, char *const argv[]);
#include<stdio.h>
#include<unistd.h>
int main(){
	char *args[]={"ls", "-l", NULL};
	printf("Before execv..\n");
	execv("/bin/ls",args);
	perror("execv failed.\n");
	return 0;
}


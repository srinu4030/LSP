//Explain how the execve() system call works and provide a code example
//execve() system call is used to replace the current running process with new process
//it does not create a new process
//it replaces the currently running program
//PID remains the same
//int execve(const char *filename, char *const argv[], char *const envp[])

#include<stdio.h>
#include<unistd.h>
int main(){
	char *args[]={"ls","-l", NULL};
	char *env[]={NULL};
	printf("Before execv\n");
	execve("/bin/ls", args, env);
	printf("Hello\n");
	perror("execve failed");//This line executes if execve fails
	return 1;
}


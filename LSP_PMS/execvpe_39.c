//execvpe()//its a GNU extension , NOT POSIX
//It combines futures of both : 
//execvp()->searches executable in path
//execve()->allows custom environment(envp)

#define _GNU_SOURCE  
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	pid_t pid;
	pid=fork();
	if(pid<0){
		perror("Fork failed");
		return 1;
	}
	if(pid==0){
		printf("Child process\n");
		char *args[]={"env", NULL};
		char *envp[]={"NAME = SRINU", "ROLE = LEARNER", NULL};
		execvpe("env", args, envp);

		perror("execvpe failed");
	}
	else{
		printf("Parent process running\n");
	}
	return 0;
}




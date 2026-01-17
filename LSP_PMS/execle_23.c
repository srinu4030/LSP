//Discuss the role of the execle() function in the exec() family of calls

#include<stdio.h>
#include<unistd.h>

int main(){
	//step1: create our own environment vaiables
	//these variables will be passed to the new program
	char *envp[]={"COURSE = Linux", "LEVEL = Bigineer","NAME = Srinu", NULL};//environment listmust end with NULL
	//step2 : execle() replaces the current program with a new one
	//"usr/bin/env"->program to execute
	//"env"->argv[0] (program name)
	//NULL-> end of arguments
	//envp-> custom environment variables
	execle("/usr/bin/env", "env", NULL, envp);
	//step3: this line executes only if execle() fails
	//Because execle() does not return on success
	perror("execle failed");
	return 0;
}


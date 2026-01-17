//Implement a c program to create a new directory named test in the current working directory


#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
int main(){
	int status;
	status=mkdir("Test", 0777);

	if(status==0){
		printf("Test directory is created successfully.\n");
		return 0;
	}
	else
		printf("Failed.\n");
	return 0;
}

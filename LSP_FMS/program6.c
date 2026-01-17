//Implement a c program to delete a file name "delete.txt"

#include<stdio.h>
#include<unistd.h>
int main(){
	if(unlink("aaa.c")==0)
		printf("File deleted successfully.\n");
	else
		perror("unlink");
	return 0;
}

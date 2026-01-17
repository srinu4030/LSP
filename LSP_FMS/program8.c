//Develop c program to move a file from one directory to another directory


#include<stdio.h>
int main(){
	if(rename("/Home/LSP_FMS/dir1/copy.txt", "/Home/LSP_FMS/dir2/copy.txt")==-1)
	       perror("rename");
	else
		printf("File moved successfully.\n");
	return 0;
}	

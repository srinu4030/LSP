//write a c program to rename a file "odfile.txt" to "newfile.txt"

#include<stdio.h>
int main(){
	if(rename("file1.txt", "file.txt")==0)
		printf("File name successfully changed.\n");
	else
		perror("rename");
	return 0;
}

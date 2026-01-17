//Write a c program to check whether "file.txt" presennt in the directory or not

#include<stdio.h>
#include<sys/stat.h>
int main(){
	struct stat st;
	if(stat("file.txt", &st)==0){
		printf("File is present.\n");
	}
	else
		printf("File is not present.\n");
	return 0;
}

//chroot() system call-> is usedd to change the root directory of the current provcess to a new loocationn in the filesystem
//int chroot(const char *path)

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	const char *new_root="/home/sandbox";//New root directory
	printf("Changing root to : %s\n", new_root);
	//change root directory
	if(chroot(new_root) !=0){
		perror("chroot failed");
		exit(1);
	}
	//change current directory to the new root
	if(chdir("/") !=0){
		perror("chdir failed");
		exit(1);
	}
	printf("New root directory set successfully.\n");
	//now any file access is restricted to new_root
	syste\m("ls /");//will list files inside/home/sandbox only
	return 0;
}

//Nice() system call in process scheduling
//nice() system call is used to change the priority of a process in scheduling
//Used to control CPU time allocation

#include<stdio.h>
#include<unistd.h>
#include<errno.h>
int main(){
	printf("Process ID : %d\n", getpid());
	//Increase the nice value by 5(lower the priority)
	int ret=nice(5);
	if(ret==-1 && errno !=0){
		perror("nice failed");
		return 1;
	}
	printf("New nice value is : %d\n", ret);
	//infinite loop to observe CPU scheduling
	while(1){
		//process keeps running
	}
	return 0;
}


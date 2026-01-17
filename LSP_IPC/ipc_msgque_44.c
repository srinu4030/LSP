//Write a program to create a message queue using the msgget system call. Ensure that the program checks for errors during the creation of process

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>

int main(){
	key_t key;
	int msqid;

	//Generate unique key
	key=ftok("msgqueuefile", 65);

	if(key==-1){
		perror("ftok failed");
		return 1;
	}
	//Create message queue
	msqid=msgget(key, 0666|IPC_CREAT);
	if(msqid==-1){
		perror("msgget failed");
		return 1;
	}

	printf("Message queue created successfully.\n");
	printf("Queue ID : %d\n", msqid);
	return 0;
}

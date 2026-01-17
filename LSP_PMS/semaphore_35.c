//Write a C program to demostrate the process synchronization using semaphores

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	key_t key=ftok("semfile", 65);
	int semid=semget(key, 1, 0666|IPC_CREAT);
	printf("semid = %d\n", semid);
	semctl(semid, 0, SETVAL,0);
	pid_t pid=fork();
	if(pid==0){
		struct sembuf smop;
		smop.sem_num=0;
		smop.sem_op=-1;
		smop.sem_flg=0;
		printf("Child waiting for parent ...\n");
		semop(semid, &smop, 1);
		printf("Child ruuning after parent signal.\n");
	}
	else{
		printf("Parent running...\n");
		sleep(3);
		struct sembuf smop;
		smop.sem_num=0;
		smop.sem_op=1;
		smop.sem_flg=0;
		semop(semid, &smop, 1);
		wait(NULL);
		//remove semaphore
		semctl(semid, 0, IPC_RMID);
		printf("Parent finished\n");
	}
	return 0;
}

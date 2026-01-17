//Write a C program  to block the SIGTERM signal using sigprocmask()

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main(){
	sigset_t block_set, old_set;
	sigemptyset(&block_set);   ///creates an empty signal set

	sigaddset(&block_set, SIGTERM); //add SIGTERM to the blocking list
	printf("Blocking SIGTERM for 10 seconds....\n");
	printf("Try sending SIGTERM : kill -TERM %d\n", getpid());

	sigprocmask(SIG_BLOCK, &block_set, &old_set); //block SIGTERM, saves old mask in old_set
	sleep(10);
	printf("Unblocking SIGTERM now...\n");

	sigprocmask(SIG_SETMASK, &old_set, NULL); //restores previous mask
	printf("SIGTERM unblocked. Program will terminate if SIGTERM is pending.\n");
	while(1)
		pause();
	return 0;
}

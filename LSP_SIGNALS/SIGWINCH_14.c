//Write a program to handle signal SIGWINCH (window size change)

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/ioctl.h>

void sigwinch_handler(int signum);
int main(){
	signal(SIGWINCH, sigwinch_handler);
	printf("PID : %d\n", getpid());
	printf("Resize the terminal window to trigger SIGWINCH\n");
	while(1){
		sleep(1);
	}
	return 0;
}
void sigwinch_handler(int signum){
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	printf("\nSIGWINCH %d received\n", signum);
	printf("New window size : Rows = %d, Columns = %d\n", w.ws_row, w.ws_col);
}



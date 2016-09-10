
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int pid=0;

void MAN(int senial){
	pid=rand()%getpid();
	printf("pare a %d\n",pid);
	kill(pid,19);
	alarm(1);
	}

int main()
{
	signal(SIGALRM,MAN);
	sigset_t set;
	sigfillset(&set);
	sigdelset(&set,SIGALRM);
	sigprocmask(SIG_BLOCK,&set,NULL);
	printf("soy %d\n",getpid());
	alarm(1);
	while(1){}
}

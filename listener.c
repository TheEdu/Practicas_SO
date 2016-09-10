
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int i=4;

void MAN(int senial){
	if (senial==10) printf("Hola\n");
	if (senial==12) {printf("Chau\n");exit(0);}
	if (senial==14) printf("...\n");
	alarm(i);
	}


int main(int argc, char **argv)
{
	alarm(i);
	signal(SIGALRM,MAN);
	signal(SIGUSR1,MAN);
	signal(SIGUSR2,MAN);
	printf("%d\n",getpid());
	while(1) {}
}


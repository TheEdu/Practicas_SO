
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int letra1='A';
int letra2='b';

void MAN1(int senial){
	if(letra1<='Z'){
		write(1,&letra1,1);
		letra1+=2;
		usleep(100000);
		raise(12);
		}
	}

void MAN2(int senial){
	if(letra2<='z'){
		write(1,&letra2,1);
		letra2+=2;
		usleep(100000);
		raise(10);
		}
	}

int main(void)
{
	signal(SIGUSR1,MAN1);
	signal(SIGUSR2,MAN2);
	raise(10);
	exit(0);
}


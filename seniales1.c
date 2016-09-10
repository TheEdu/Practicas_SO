
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int i=7;

//alarma que dispara una senial que vuelve a setear una alarma//


void MAN(int senial){
		printf("hola soy la senial usr1\n");
		alarm(i);
		
	}

void MAN1(int senial){
		printf("hola soy la senial alrm\n");
		//kill(getpid(),SIGUSR1);
		raise(10);
	}

int main(int argc, char **argv)
{
	printf("PID:%d \n",getpid());
	signal(SIGUSR1,MAN);
	signal(SIGALRM,MAN1);
	//alarm(i);
	raise(10);
		
	while (1) {
		printf("trabajando\n");
		sleep(1);
	}
	
	return 0;
}


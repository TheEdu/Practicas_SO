
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void MAN(int senial){
	usleep(100000);
	}

int main(int argc, char **argv)
{
	pid_t pid=fork();
	signal(SIGUSR1,MAN);
	
	if (pid==0) {
		int letra='A';
		raise(10);
		while(letra<='Z'){
			write(1,&letra,1);
			letra+=2;
			kill(getppid(),10);
			pause();
			}
		
		} else {
			int letra='b';
			while(letra<='z'){
				pause();
				write(1,&letra,1);
				letra+=2;
				kill(pid,10);
				}			
			}
	exit(0);
}


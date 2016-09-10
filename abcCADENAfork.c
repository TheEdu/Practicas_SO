
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char **argv)
{
	int letra='A';
	int pid=fork();
	while(letra<='Z'){
		if (pid==0) {
			usleep(100000);
			letra++;
			pid=fork();
			}
		else{
			write(1,&letra,1);
			wait(NULL);
			usleep(100000);
			write(1,&letra,1);
			exit(0);
			}	
		}
		exit(0);
}



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char **argv)
{
	char frase[64]="Hola!!";
	int pid=fork();
	int i=0;
	while (frase[i]!='\0'){
		if (pid==0) {
			i++;
			usleep(500000);
			pid=fork();
			}else{
				printf("%c y %d\n",frase[i],getpid());
				wait(NULL);
				usleep(500000);
				i=5-i;
				printf("%c y %d\n",frase[i],getpid());
				exit(0);
				}
		}
	exit(0);
}


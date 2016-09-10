

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
	int archivo= open("abcd",O_CREAT|O_APPEND|O_RDWR,0600);
	pid_t pid=fork();
	if (pid==0) {
		int letra='A';
		while (letra <= 'Z'){
			write(archivo,&letra,1);
			//write(1,&letra,1);
			printf("\n");
			letra+=1;
			}
		exit(0);
		}
	wait(NULL);
	lseek(archivo,0,0);
	char letra[4];
	while(read(archivo,letra,4)){write(1,&letra,4);usleep(100000);}
	close(archivo);
	exit(0);
}


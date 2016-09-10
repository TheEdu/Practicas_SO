
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int p[2];
	pipe(p);
	printf("PROCESOS\n");
	int pid=fork();
	printf("%d\n",getpid());
	int nombre=getpid();
	if (pid==0)
	write(p[1],&nombre,1);
	else{
	wait(NULL);
	printf("===================\n");	
	read(p[0],&nombre,1);
	printf("soy %d\n",getpid());
	printf("mi hijo es %d (lo dice el padre!!!)\n",nombre);
}
	return 0;
}


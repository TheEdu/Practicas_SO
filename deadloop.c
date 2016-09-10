#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int p[2];char letra;
	pipe(p);
	fork();
	printf("%d\n",getpid());
	read(p[0],&letra,1);
	
	
	return 0;
}


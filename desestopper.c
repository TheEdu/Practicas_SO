
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>



int main(void)
{
	int i;
	for (i=0;i<getpid();i++) kill(i,18);
	exit(0);
}

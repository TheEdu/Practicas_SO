
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>


int main(int argc, char **argv)
{
	int pid=atoi(argv[1]);
	kill(pid,9);
	return 0;
}


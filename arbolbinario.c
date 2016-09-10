#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

//arbol triario de 3 niveles)//

int main(int argc, char **argv)
{
	int dios=getpid();
	int pid,i;
	pid=fork();
	for(i=1; i<3;i++) if (pid>0) pid=fork();

	if (pid==0) {
		pid=fork();
		for(i=1; i<3;i++) if (pid>0) pid=fork();
		}
	sleep(1);	
	if (getpid()==dios) system("ps -l");
	//while(1){}
	sleep(1);
	
	return 0;
}


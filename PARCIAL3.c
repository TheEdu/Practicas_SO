
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(void)
{
int pid1=fork();	
if (pid1==0) {
	int pid2=fork();
	if (pid2==0)fork();
	}
if (pid1>0) fork();
wait(NULL);
wait(NULL);
printf("soy %d y mi papi es %d\n",getpid(),getppid());	
exit(0);
}

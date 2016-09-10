
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(void)
{
	int pid;
	char frase[24]=" Hola Mundo";
	int i=0;
	while((frase[i])!='\0'){
		i++;
		pid=fork();
		if (pid>0) break;
		}
		wait(NULL);
		printf("SOY %d: %c\n",getpid(),frase[11-i]);
	
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(void)
{
	int pid=123;
	char frase[24]=" Hola Mundo!";
	int i=0;
	while((frase[i])!='\0'){
		i++;
		pid=fork();
		pid=fork();
		pid=fork();
		if (pid>0) {printf("SOY %d: %c\n",getpid(),frase[i]);break;}
		}
		wait(NULL);
	return 0;
}

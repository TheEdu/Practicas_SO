

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

//comunicacion unidireccional


int main(void)
{
	pid_t pid;
	int p[2];
	pipe(p);
	pid=fork();
	if (pid>0){
		close(p[0]);
		int letra='A';
		while (letra<='Z'){
			write(p[1],&letra,1);
			letra++;
		}
		close(p[1]);
		//wait(NULL);//el padre espera a que el hijo termine de escribir
		exit(0);
	}else{
		close(p[1]);
		char letra;
		while(read(p[0],&letra,1)>0) printf("letra %c\n",letra);
		close(p[0]);
		exit(0);
	}	
	
}


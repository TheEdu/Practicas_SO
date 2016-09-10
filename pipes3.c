

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

//comunicacion bidireccional

int main(void)
{
	
	int p1[2];
	int p2[2];
	pipe(p1);
	pipe(p2);
	pid_t pid=fork();
	
	if (pid>0) {  
		close(p1[0]);
		close(p2[1]);
		int letra='A';
		while (letra<='Z'){
			write(p1[1],&letra,1);
			letra++;
		}
		close(p1[1]);
		//wait(NULL); // el hijo lee todo primero y luego el padre lee todo
		while(read(p2[0],&letra,1)>0) printf("Padre lee %c\n",letra);
		close(p2[0]);
		exit(0);
			
		
	}else{
		close(p1[1]);
		close(p2[0]);
		int letra='a';
		while (letra<='z'){
			write(p2[1],&letra,1);
			letra++;
		}
		
		close(p2[0]);
		while(read(p1[0],&letra,1)>0) printf("Hijo lee %c\n",letra);
		close(p1[0]);
		exit(0);
		}


}


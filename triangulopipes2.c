#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void man(int senial) {
	usleep(100);
};


int main(int argc, char **argv)
{
	int p1[2], p2[2], p3[2];
	int letra;
	
	//creo pipes
	pipe(p1);
	pipe(p2);
	pipe(p3);
	signal(SIGUSR1,man);
	
	int pid=fork();
	if (pid==0) {
		pid=fork();
				
		if(pid==0) {
			//NIETO (proceso 3) escribe en p3, lee de p2
			close(p1[0]);
			close(p1[1]);
			close(p2[1]);
			close(p3[0]);
			while(1) {
					pause();
					printf("3- \n");
					while (read(p2[0],&letra,1)>0) {
						if(letra=='+') break;
						printf("%c\n", letra);
						write(p3[1],&letra,1);
						letra++;
						write(p3[1],&letra,1);
					};
					kill(getppid()-1,SIGUSR1);
					pause();
			};
		}
		else {
		//HIJO (proceso 2) escribe en p2, lee de p1
		close(p1[1]);
		close(p2[0]);
		close(p3[0]);
		close(p3[1]);
		while(1) {
			pause();
			printf("3- \n");
			while (read(p1[0],&letra,1)>0) {
					if(letra=='+') break;
					printf("%c\n", letra);
					write(p2[1],&letra,1);
					letra++;
					write(p2[1],&letra,1);
			};
			kill(pid,SIGUSR1);
			pause();
		};	
		}	
	}
	else {
		//PADRE (proceso 1) escribe en p1, lee de p3
		close(p1[0]);
		close(p2[0]);
		close(p2[1]);
		close(p3[1]);
		sleep(2);
		write(p1[1],"a",1);
		write(p1[1],"+",1);
		printf("1- Arranco: a\n");
		kill(pid,SIGUSR1);
		while(1) {
				pause();
				printf("3- \n");
				while (read(p3[0],&letra,1)>0) {
					if(letra=='+') break;
					printf("%c\n", letra);
					write(p1[1],&letra,1);
					letra++;
					write(p1[1],&letra,1);
					
				};
				kill(pid,SIGUSR1);
				pause();
		};
	};	
	
	
	return 0;
}


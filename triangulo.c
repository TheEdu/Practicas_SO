
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int a=0,b=1,c=2; 
int i;
char letra;
int p1[2];
int p2[2];
int p3[2];

	
void MAN1(int senial){
	for (i=0;i<a;i++) { read(p3[0],&letra,1);
						printf("%c\n",letra);
						usleep(250000);
						write(p1[1],&letra,1); }
	a=a+3;
	write(p1[1],"a",1);
	//sleep(1);
	printf("comiendo...'a'\n");
	//sleep(1);
	kill(getpid()+1,10);
	
	}


void MAN2(int senial){
		for (i=0;i<b;i++) { read(p1[0],&letra,1);
							printf("%c\n",letra);
							usleep(250000);
							write(p2[1],&letra,1); }
	b=b+3;
	write(p2[1],"b",1);
	//sleep(1);
	printf("comiendo...'b'\n");
	//sleep(1);
	kill(getpid()+1,10);
	
	}


void MAN3(int senial){
		for (i=0;i<c;i++) { read(p2[0],&letra,1);
							printf("%c\n",letra);
							usleep(250000);
							write(p3[1],&letra,1); }
	c=c+3;
	write(p3[1],"c",1);
	//sleep(1);
	printf("comiendo...'c'\n");
	//sleep(1);	
	kill(getpid()-2,10);
	
	}
	
int main(void)
{
	pipe(p1);
	pipe(p2);
	pipe(p3);
	// tengo 3 pipes q son heredados por todos los procesos//

	//estructura de forks//
	int nro=0;
	if(fork()==0){
		nro=2;
		if(fork()==0) nro=3;
		}else nro=1;
	//tres procesos en cadena (abuelo(1)----padre(2)----hijo(3))//
	
	//cierre de pipes//
	switch (nro){
		case 1 : signal(SIGUSR1,MAN1);close(p3[1]);close(p1[0]);close(p2[0]);close(p2[1]); break;
		case 2 : signal(SIGUSR1,MAN2);close(p1[1]);close(p2[0]);close(p3[0]);close(p3[1]); break;
		case 3 : signal(SIGUSR1,MAN3);close(p2[1]);close(p3[0]);close(p1[0]);close(p1[1]); break;
	}
	//triangulo de pipes//
	
	//presentandose//
	printf("soy %d\n",getpid());
	sleep(2);
	
	//shoot and infinite loop//
	if (nro==1) kill(getpid(),10);
	while(1){}
	exit(0);
}

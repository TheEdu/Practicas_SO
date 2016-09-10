
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int a=0,b=1,c=2; 
int i;
int letra='@';
int p1[2];
int p2[2];
int p3[2];
int nombre;
int nombre2;
int abuelo;
int padre,hijo;

void MAN1(int senial){
	for (i=0;i<a;i++) { read(p3[0],&letra,1);
						printf("%c\n",letra);
						usleep(250000);
						write(p1[1],&letra,1); }
	
	a=a+3;
	letra++;
	if (letra=='[') letra='A';
	write(p1[1],&letra,1);
	printf("comiendo...%c\n",letra);
	sleep(1);
	kill(/*nombre*/padre,10);
	
	}


void MAN2(int senial){
		for (i=0;i<b;i++) { read(p1[0],&letra,1);
							printf("%c\n",letra);
							usleep(250000);
							write(p2[1],&letra,1); }
	
	b=b+3;
	letra++;
	if (letra=='[') letra='A';
	write(p2[1],&letra,1);
	printf("comiendo...%c\n",letra);
	sleep(1);
	kill(/*nombre*/hijo,10);
	
	}


void MAN3(int senial){
		for (i=0;i<c;i++) { read(p2[0],&letra,1);
							printf("%c\n",letra);
							usleep(250000);
							write(p3[1],&letra,1); }
	
	c=c+3;
	letra++;
	if (letra=='[') letra='A';
	write(p3[1],&letra,1);
	printf("comiendo...%c\n",letra);
	sleep(1);	
	kill(/*nombre2*/abuelo,10);
	
	}
	
int main(void)
{
	pipe(p1);
	pipe(p2);
	pipe(p3);
	int pid2a1[2];
	int pid3a2[2];
	int pid1a3[2];
	pipe(pid2a1);
	pipe(pid3a2);
	pipe(pid1a3);
	// tengo 3 pipes q son heredados por todos los procesos//
	abuelo=getpid();
	
	//estructura de forks//
	int nro=0;
	if((padre=fork())==0){
		nro=2;
		if((hijo=fork())==0) nro=3;
		}else nro=1;
	//tres procesos en cadena (abuelo(1)----padre(2)----hijo(3))//
	
	//cierre de pipes//
	switch (nro){
		case 1 : signal(SIGUSR1,MAN1);close(p3[1]);close(p1[0]);close(p2[0]);close(p2[1]); break;
		case 2 : signal(SIGUSR1,MAN2);close(p1[1]);close(p2[0]);close(p3[0]);close(p3[1]); break;
		case 3 : signal(SIGUSR1,MAN3);close(p2[1]);close(p3[0]);close(p1[0]);close(p1[1]); break;
	}
	//triangulo de pipes//
	
	//a quien tengo q darle las cosas?//
	nombre2=getpid();
	nombre=getpid();
	//pid2a1
	if (nro==2)
	write(pid2a1[1],&nombre,1);
	if (nro==1)
	read(pid2a1[0],&nombre,1);
	//pid3a2
	if (nro==3)
	write(pid3a2[1],&nombre,1);
	if (nro==2)
	read(pid3a2[0],&nombre,1);
	//pid1a3
	if (nro==1)
	write(pid1a3[1],&nombre2,1);
	if (nro==3)
	read(pid1a3[0],&nombre2,1);
	//worth it//
	
	
	//presentandose//
	printf("soy %d\n",getpid());
	sleep(1);
	
	//shoot and infinite loop//
	if (nro==1) kill(getpid(),10);
	while(1){}
	exit(0);
}


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>  // funciones unix (sleep,read(), write(), etc)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>


void *fhilo2(void *x){
int letra='A';
	int pid=fork();
	while(letra<='Z'){
		if (pid==0) {
			usleep(100000);
			letra++;
			pid=fork();
			}
		else{
			write(1,&letra,1);
			wait(NULL);
			usleep(100000);
			write(1,&letra,1);
			exit(0);
			
			}	
		}

	pthread_exit(0);
	}

void *fhilo1(void *x){
	int letra='a';
	int pid=fork();
	while(letra<='z'){
		if (pid==0) {
			usleep(100000);
			letra++;
			pid=fork();
			}
		else{
			write(1,&letra,1);
			wait(NULL);
			usleep(100000);
			write(1,&letra,1);
			exit(0);
			
			}	
		}

	pthread_exit(0);
	}

int main(int argc, char **argv)
{
	int pid=fork();
	if (pid==0){
	pthread_t hilo1,hilo2;
	pthread_create(&hilo1,NULL,fhilo1,NULL);
	pthread_create(&hilo2,NULL,fhilo2,NULL);
	pthread_join(hilo1,NULL);
	pthread_join(hilo2,NULL);
	exit(0);
	} else {	
	pthread_t hilo1,hilo2;
	pthread_create(&hilo1,NULL,fhilo1,NULL);
	pthread_create(&hilo2,NULL,fhilo2,NULL);
	pthread_join(hilo1,NULL);
	pthread_join(hilo2,NULL);
	exit(0);
	}
	
}


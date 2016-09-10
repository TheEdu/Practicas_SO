
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>  // funciones unix (sleep,read(), write(), etc)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void fhilo1(void  *x){
	int letra='A';
	while(letra<='Z') {
		pthread_mutex_lock(&mutex1);
		usleep(100000);
		write(1,&letra,1);
		/*printf("%c\n",letra);*/
		letra+=2;
		pthread_mutex_unlock(&mutex2);
		}
	pthread_exit(0);	
	}
	
void fhilo2(void *x){
	int letra='b';
	while(letra<='z') {
		pthread_mutex_lock(&mutex2);
		usleep(100000);
		write(1,&letra,1);
		/*printf("%c\n",letra);*/
		letra+=2;
		pthread_mutex_unlock(&mutex1);
		}
	pthread_exit(0);
	}

int main(int argc, char **argv)
{
	pthread_mutex_init(&mutex1,NULL);
	pthread_mutex_init(&mutex2,NULL);
	pthread_mutex_lock(&mutex2);
	pthread_t hilo1, hilo2;
	pthread_create(&hilo1,NULL,(void *)fhilo1,NULL);
	pthread_create(&hilo2,NULL,(void *)fhilo2,NULL);
	pthread_join(hilo1,NULL);
	pthread_join(hilo2,NULL);
	exit(0);
}


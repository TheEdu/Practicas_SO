//      thr3.c
//      
//      Copyright 2012 grchere <grchere@debian2>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
/*
 * UTN FRD SO 
 * Ejecucion de dos hilos concurrentes fhilo1 y fhilo2 en forma intercalada:
 * fhilo1 - fhilo2 - fhilo1 - fhilo2 ...
 * utilizando para ello los mutex m1 y m2
 * la funcion main() espera a la finalizacion de fhilo1 y fhilo2 utilizando join
 * 
 * La inicializacion estatica de mutex usando PTHREAD_MUTEX_INITIALIZER debe realizarse
 * en la misma declaracion del mutex y no despues.
 * Otra opcion es inicializar los mutex en forma dinamica tal como se realiza en el libro
 * de Sistemas Operativos, Ejercicios de Programacion en Lenguaje C, parte I
 * 
 * linkear como:
 * gcc -Wall -o thr3 thr3.c -pthread
 * 
 * Lic. Juan C. Romero / Guillermo Cherencio
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *fhilo1();
void *fhilo2();

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char **argv)
{
	pthread_t hilo1,hilo2;

	printf("inicio main()\n");
	pthread_mutex_lock(&m2);
	pthread_create(&hilo1,NULL,fhilo1,NULL);
	pthread_create(&hilo2,NULL,fhilo2,NULL);
	pthread_join(hilo1,NULL);
	pthread_join(hilo2,NULL);
	printf("fin main()\n");
	exit(0);
}

void *fhilo1() {
	int i;
	for(i=0;i<10;i++) {
		pthread_mutex_lock(&m1);
		printf("soy hilo1\n");
		sleep(1);
		pthread_mutex_unlock(&m2);
	}
	pthread_exit(0);
}

void *fhilo2() {
	int i;
	for(i=0;i<10;i++) {
		pthread_mutex_lock(&m2);
		printf("soy hilo2\n");
		pthread_mutex_unlock(&m1);
	}
	pthread_exit(0);
}

//      thr1.c
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
 * Ejecucion de un hilos concurrente fhilo con la funcion main(), modificando
 * el valor de la variable global a
 * Jugar con exit() y pthread_exit() poner printfs antes y despues de
 * funciones para ver como ejecuta el codigo (y si incluso, se ejecuta!)
 * Jugar con poner y quitar join()
 * 
 * linkear como:
 * gcc -Wall -o thr1 thr1.c -pthread
 * 
 * Lic. Juan C. Romero / Guillermo Cherencio
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *fhilo();
int a=0;

int main(int argc, char **argv)
{
	pthread_t hilo;
	printf("inicio main a vale: %d\n",a);
	pthread_create(&hilo,NULL,fhilo,NULL);
	int status=0;
	pthread_join(hilo,&status);
	printf("fin main a vale: %d y mi status es %d\n",a,status);
	exit(0);
	//sleep(3);
	//printf("main2 %d\n",a);
	//pthread_exit(0);
	//printf("main3 %d\n",a);  // esta linea no deberia ejecutarse luego de pthread_exit
}

void *fhilo() {
	//printf("inicio fhilo\n");
	a+=2;
	sleep(1);
	//printf("fin fhilo\n");
	pthread_exit(a);
}

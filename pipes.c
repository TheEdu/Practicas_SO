/*PIPES (sin nombre) *conectan solo procesos emparentados
					 *unidireccional
					 *lectur destructiva
					 *almacenamiento finito
					 *Orden de lectur igual Orden de escritura
					 *El lector se bloquea en lectura cuando el pipe esta vacio y hay un escritor
					 *El escritor se bloquea en la escritura cuando el pipe esta lleno y hay un lector
	   
	                                                         |*Si el pipe esta vacio y no hay escritor el lector no se bloquea en la lectura
por defecto no se cumplen estas dos cuando se crea el pipe---|
		                                                     |*Cuando no hay lector y el escritor quiere escribir, el escritor muere
*/


//FIFO (con nombre) conectan solo procesos emparentados/independientes

#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int main(void)
{
	//int pipe(int p[]);
	//close(p[1]);
	//close(p[0]); //crea pipe sin nombre, devuelve 0/-1, p[0]-->lectura, p[1]-->escritura
	int p[2];
	pipe(p);
	int cont=0;
	while(1){
		alarm(1);
		write(p[1],"X",1);
		cont++;
		printf("cont=%d\n",cont);
		alarm(0);
	}
	
	return(0);
}


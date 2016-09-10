#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//ver la maxima capacidad de almacenamiento en un pipe

int main(void)
{
	int p[2];
	pipe(p);
	int cont=0;
	while(1){
		alarm(1);
		write(p[1],"algo",1);
		cont++;
		printf("cont=%d\n",cont);
		alarm(0);
	}
	
	return(0);
}


#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i=0;
	scanf("%d",&i);
	char frase[i];
	scanf("%s",frase);
	int j;
	for(j=0;j<i;j++) printf("tu frase[%d] es: %c\n",j,frase[j]);
	//printf("tu frase es: %s\n",frase);	
	return 0;
}


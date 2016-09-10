/*

  UTN FRD SO
  Shell básico 31/03/14

*/


#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const

char prompt_Type[256]="prompt: ";


void  parse(char *line, char **argv)
{
     while (*line != '\0') {       
          while (*line == ' ' || *line == '\t' || *line == '\n')
				*line++ = '\0';     
          *argv++ = line;          
          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++;             
     }
     *argv = '\0';                 
}

void ingresar(char *line)
{
	printf("%s",prompt_Type);
	gets(line);
    while (*line=='\0' || *line == ' ' ||*line == '\t' || *line== '\n') {
		printf("%s",prompt_Type);
		gets(line);
	}
	
}


int main(void) {
   char comando[256],*argv[64];
   pid_t pid;
   int status=0;

   ingresar(comando);
   parse(comando,argv);
   while(strcmp(*argv,"quieroSalir")) {
       pid = fork();
       if ( pid == 0 ) { 
          execvp(*argv,argv); 
          printf("\ncomando no valido [%s]\n",comando);
          exit(1);
       } else {
          pid = wait(&status);
          printf("\ntermino padre id = %d\ntermino hijo id =%d\n",getpid(),pid);
          if (status==256) printf("hijo termino mal!\n");
          ingresar(comando);
          parse(comando,argv);
       }
   }
   exit(0);
}



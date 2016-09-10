

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (int argc,char **argv)
{
int i;
for (i=1; i<argc;i++){
int pid=fork();
if(pid==0) {
execlp(argv[i],argv[i],NULL);
exit(1);
}
wait(NULL);
//sleep(2);
}

exit(0);
}

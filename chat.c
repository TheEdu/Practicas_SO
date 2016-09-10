
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
//
//
//
//

	pid=fork();
	if (pid>0){
		pid=fork();
			if(pid>0){
				close(p1[0]);
				close(p2[0]);
				close(p2[1]);
				//ESCRIBIR EN p1
			}else{
				close(p1[0]);
				close(p1[1]);
				close(p2[1]);
				//LEE DE p2
			}
	}else{
		pid=fork();
		if(pid>0){
			close(p1[0]);
			close(p1[1]);
			close(p2[0]);
			//ESCRIBE EN p2
		}else{
			close(p2[0]);
			close(p2[1]);
			close(p1[1]);
			//LEE DE p1
	exit(0);
}

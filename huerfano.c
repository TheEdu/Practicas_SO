
#include <stdio.h>

int main(int argc, char **argv)
{
		if (fork()==0) {sleep(1);system("ps eax");}
		exit(0);
}


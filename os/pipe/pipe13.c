#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGSIZE 16

int main(){

	char *msg1 = "HelloMSIS#1";
	char inbuf[MSGSIZE];
	
	int p[2],pid,j; //p[0] is read p[1] is write
	
	pipe(p);
	
	pid = fork();
	
	if(pid>0){//parent
		close(p[0]);//read is closed 
		write(p[1],msg1,MSGSIZE);
	}
	if(pid == 0){//child
		close(p[1]);
		read(p[0],inbuf,MSGSIZE);
		printf("%s\n",inbuf);
	}
	exit(0);
}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MSGSIZE 16

int main(){

	char *msg1 = "hellMSIS#1";
	char *msg2 = "hellMSIS#2";
	char *msg3 = "hellMSIS#3";
	
	char inbuf[MSGSIZE];//buffer
	 
	int p[2];//file descriptor p[0] read, p[1] will be for write
	
	pipe(p);
	
	write(p[1],msg1,MSGSIZE);
	write(p[1],msg2,MSGSIZE);
	write(p[1],msg3,MSGSIZE);
	
	for(int j=0;j<3;j++){
		read(p[0],inbuf,MSGSIZE);
		printf("%s\n",inbuf);
	}
	exit(0);

}

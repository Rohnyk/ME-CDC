#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#define MSGSIZE 16

int main(){

char *msg1 ="HelloMSIS#1";
char *msg2 ="HelloMSIS#2";
char *msg3 ="HelloMSIS#3";
int p[2];
char inbuf[MSGSIZE];
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

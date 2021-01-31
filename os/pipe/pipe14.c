#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
	char *one[3],*two[2];
	int ret;
	
	one[0] = "ls";
	one[1] = "-ll";
	one[2] = (char*)0; //stdout STDIN(1) , STDOUT(0), STDERR(2)

	two[0] ="sort";
	two[1] =(char)0;

	ret = join(one,two);
	printf("join returned %d\n",ret);
	exit(0);
}


int join(com1,com2)
char *com1[],*com2[];
{

	int p[2],status;
	switch(fork()){
		case -1:
			perror("ERROR");
		case 0:
			break;
		default:
			wait(&status);
		return status;
	}
	
	if(pipe(p)<0)
		perror("pipe call in join");
	switch(fork()){
		case -1:
			perror("Second fork call in join\n");
		case 0:
			close(1);
			dup(p[1]);
			close(p[0]);
			close(p[1]);
			execl("/bin/ls",com1[0],com1[1],com1[2]);
			perror("1st execl call in join\n");
		default:
			close(0);
			dup(p[0]);
			close(p[0]);
			close(p[1]);
			execl("/bin/sort",com2[0],com2[1]);
			perror("1st execl call in join\n");
	
	}
	
}

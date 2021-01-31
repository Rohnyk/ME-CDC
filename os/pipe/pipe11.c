#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int p[2],retval,i=0;
	retval=pipe(p);
	while(1){
//	printf("p[0] is %d p[1] is %d\n",p[0],p[1]);	
	if(retval == -1){
		printf("Max no of pipes tat can be opneded concurrenlty are %d\n",i);
		exit(1);
	}
	i++;
	printf("%d %d\n",p[0],p[1]);
	}

}

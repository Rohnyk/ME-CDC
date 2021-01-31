#include<stdio.h>

int main(){
	int p[2];
	pipe(2);
	printf("p[0] is %d p[1] is %d\n",p[0],p[1]); //p[0] is read end and p[1] is the write end

}

//Program to show demo of CLA
#include<stdio.h>
int main(int argc, char *argv[])
{
	printf("Number of arguments passed:%d",argc);
	for(int i=0;i<argc;i++)
		printf("Argument %d:%s\n",i,argv[i]);

}
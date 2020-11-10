#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int sum(int n)
{
	static int sum=0;
	sum+=n;
    return sum;    
}

float average(int n)
{
	static int i=0;
	i+=1;
	static int sum2=0;
	sum2+=n;
	return (float)sum2/i;
}

int product(int n)
{
	static int product=1;
	product*=n;
}

void main(int argc,char *argv[])
{
	int n,i=1;
	do
	{	
	n=atoi(argv[i++]);
	if(n==999)
		break;
	printf("Sum=%d\n",sum(n));
	printf("Average=%f\n",average(n));
	printf("product=%d\n",product(n));
    }while(i<argc);

}
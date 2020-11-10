#include<stdio.h>


int sum(int *a)
{
	int sum=0;
	for(int i=0;i<10;i++)
    	sum+=a[i];
    return sum;    
}

float average(int *a)
{
	int sumarray= sum(a);
	return (float)sumarray/10;
}

int product(int *a)
{
	int product=1;
	for(int i=0;i<10;i++)
		product*=a[i];
}

void main()
{
	int a[10];
	printf("Enter the 10 numbers:\n");
	for(int i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("Sum=%d\n",sum(a));
	printf("Average=%f\n",average(a));
	printf("product=%d\n",product(a));
}
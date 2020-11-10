#include<stdio.h>

int sum(int *num,int nlen)
{
	int sum=0;
	for(int i=0;i<nlen;i++)
		sum+=num[i];
    return sum;
}

float avg(int *num,int nlen)
{
	int sum=0;
	for(int i=0;i<nlen;i++)
		sum+=num[i];
    return sum/nlen;
}

int product(int *num,int nlen)
{
	int product=1;
	for(int i=0;i<nlen;i++)
		product*=num[i];
    return product;
}

int main()
{
	int nlen;
	printf("Enter the length of the array:");
	scanf("%d",&nlen);
	int num[nlen];
	printf("Enter the Numbers:");
	for(int i=0;i<nlen;i++)
		scanf("%d",&num[i]);
	printf("Sum=%d",sum(num,nlen));
	printf("Average=%f",avg(num,nlen));
	printf("Product=%d",product(num,nlen));
    return 0;	
}
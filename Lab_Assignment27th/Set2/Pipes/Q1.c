#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define Max_size 10

int sum(int *a)
{
	int sum=0;
	for(int i=0;i<Max_size;i++)
		sum+=a[i];
	return sum;
}

float average(int sum)
{
	return (float)sum/Max_size;
}


int main()
{
	int a[Max_size];
    printf("\nEnter the Elements:\n");
    for(int i=0;i<Max_size;i++)
        scanf("%d",&a[i]);
	int fd1[2];
    if(pipe(fd1)==-1)
    	fprintf(stderr,"pipe failed");
    pid_t pid;
    pid=fork();
    if(pid<0)
    	fprintf(stderr,"fork failed");
    else
    	if(pid==0)
    {
    	close(fd1[0]);
    	int num=sum(a);
    	printf("%d\n",num);
    	write(fd1[1],&num,sizeof(num));
    	close(fd1[1]);
    }
    else
    {
    	int sum;
    	float avg;
    	wait(NULL);
    	close(fd1[1]);
    	read(fd1[0],&sum,sizeof(sum));
    	printf("%d\n",sum);
        avg=average(sum);
        close(fd1[0]);
        printf("The average of the given array is:%f",avg);
 
    }
    return 0;
    
}